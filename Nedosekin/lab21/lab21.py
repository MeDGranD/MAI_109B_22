import os
import sys
import argparse
import shutil

def get_arguments():
    parser = argparse.ArgumentParser(description='File')
    parser.add_argument('-f', '--file_to_copy', type=str, help='Filename to copy')
    parser.add_argument('-n', '--num_copies', type=int, help='number of copies')
    args = parser.parse_args()
    return str(args.file_to_copy), int(args.num_copies)

def check_file(file_to_copy):
    try:
       file = open(file_to_copy)
    except IOError as e:
       print('file not found')
    finally:
       file.close () 
    

def generation(file_to_copy, num_copies):
    for i in range(1, num_copies + 1):
        new_filename = file_to_copy + str(i)
        shutil.copy(f'{file_to_copy}', f'{new_filename}')

def main():
    file_to_copy, num_copies = get_arguments()
    check_file(file_to_copy)
    generation(file_to_copy, num_copies)

if __name__ == "__main__":
    main()


