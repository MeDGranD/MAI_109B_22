import argparse
import os
import re
from typing import List
from typing import Dict

def get_args():
    parser = argparse.ArgumentParser(description='runs build or tests')
    parser.add_argument('--run_type', dest='run_type', help='run_type')
    parser.add_argument('--files', dest='files', help='list of changes files', default=[])

    args = parser.parse_args()
    if args.run_type != 'build' and args.run_type != 'tests':
        raise Exception('You need to choose on of options: build or tests')

    return args.run_type, args.files


def build():
    os.system('make build')


def run_tests():
    os.system('make test')


def groub_by_labs(files: List[str]) -> Dict[str, str]:
    labs_category: Dict[str, str] = {}
    for file in files:
        search_result = re.search('lab2[0-9]', file)
        if search_result is None:
            search_result = re.search('KP[0-9]', file)
        if search_result is None:
            continue
        else:
            lab = search_result.group()
        labs_category[lab] = os.path.join(file.split(lab)[0], lab)
        print('for ' + lab + ' add path: ' + os.path.join(file.split(lab)[0], lab))

    return labs_category

def change_dir_back(path: str):
    cur_dir = os.path.abspath(os.curdir)
    os.chdir(path)
    yield
    os.chdir(cur_dir)


def main():
    run_type, files = get_args()
    print('run_type is ' + run_type)
    print('files to check ' + files)
    labs_category = groub_by_labs(files)
    for _, path in labs_category.items():
        with change_dir_back(path):
            print('running for ' + path)
            if run_type == 'build':
                build()
            elif run_type == 'tests':
                run_tests()


if __name__ == '__main__':
    main()
