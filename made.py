'''
Author - Debag101
Date - 16 - 6 - 2023
Purpose grid MAKER
'''
# Importing random package
import random as rand

# Displaying context to user
def display():
    print("========GRID MAKER========\n")
    print("This program will make a sample grid based on your grid filler characters !")

# Gets grid filler characters
def getFiller():
    while True:
        try: 
            # Gets character count
            count = int(input("How many characters you have ? : "))
        except ValueError as e:
            # Raises the error
            raise(e)
        else:
            # Getting the chars
            word_list = []
            for i in range(count):
                word_list.append(input(f"Enter the character number {i+1} : "))
            return word_list


# Generating the actual grid
def generategGrid(words):
    try:
        grid_row = int(input("Enter row length of grid : "))
        grid_col = int(input("Enter coloumn length of grid : "))
    except ValueError as e:
        raise(e)
    else:
        grid = []
        for i in range(grid_row):
            row = []
            for j in range(grid_col):
                row.append(rand.choice(words))
                grid.append(row)    
        print(grid)

# Writing main
def main():
    display()
    generategGrid(getFiller())

# Executing main
main()
