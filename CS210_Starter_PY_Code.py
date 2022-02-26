#CS 210 Programming Languages
#Project 3 Module 7
#Author: Kyle Latimer
#Date: 2/22/2022
#
#Program Description:
#This program will ask the end user for input. If the end user chooses option 1, the program will open a 
#file, file CS210_Project_Three_Input_File.txt, will read the file, and will create file frequency.dat. 
#The information will then be soted and alphabatized in a list. The C++ Source code will then output the
#data for the end user. 
#
#If the user chooses option 2, the program will then ask the user what item they would like to be displayed. 
#The user will then input an item. The program will then convert the input to a capitalized string, so case 
#does not affect the output. The program will then output the freequency that specified item. 
#
#If the user chooses option 3, the program will utput a histogram of each item and it's frequency for the 
#user.
#
#If the user inputs option 4, the program will finish and exit. */


import re
import string
from collections import Counter # ImportCounter gives the ability to count frequency of words in file.                           

#Start of provided source code CS210_Starter_Py_Code.py.

def printsomething(): #Not called in this application.
    print("Hello from python!")

def PrintMe(v): #Not called in this application.
    print("You sent me: " + v)
    return 100;

def SquareValue(v): #Not called in this application.
    return v * v

def read_File():

    # This function will read a file
    # It will count the total amount of each product
    # Then it will print it to the console
    

    ticket = open("CS210_Project_Three_Input_File.txt") #Ticket creates an object that opens text file.
    products = ticket.read().split() #Product creates an object that holds each line info from ticket object.
    unique_Product = sorted(set(products))

    
# Print statement and if else statement for whitespace. 
    for word in unique_Product: 
        numLetters = len(word) 
        if (products.count(word) > 9):
            lengthPrint = 69 - numLetters
        else:
            lengthPrint = 70 - numLetters
        charPrint = '*'
                
        print("*******************************************************************************")
        
        print("*",products.count(word), " : ",  word, '{1:>{0}}'.format(lengthPrint, charPrint))
        print("*******************************************************************************")
        
    

    ticket.close() #Closes object, prevents memory leak.

    

def locate_Total_Product_Amount(v):
    # Takes a string from C++ user input
    # Will search through text file to count the total occurance of specified item.
    # Will then print to console the item and occurances. 

    
    ticket = open("CS210_Project_Three_Input_File.txt")#Creates object that opens file.
    products = ticket.read().split() #Creates an object that holds each line information from ticket object.
    unique_Product = sorted(set(products)) #Sorts the items.
    ticket.close() #Closes object, prevents memory leak.


    totalNum = 0 #Number to be used by C++ for output. 
    total_Num_Inventory = 0 #Then counts the amount of times loop iterates.
    total_Num_Inventory_Count = 0 # Holds total inventory  number in file CS210_Project_Three_Input_File.txt.

    for word in unique_Product: # Obtains total amount of items in list.
        total_Num_Inventory_Count += 1

    for word in unique_Product: #Finds the element in unique_Product that is the requested string from user
        temp_String = word
        total_Num_Inventory += 1
        if (temp_String == v.capitalize()):#Capitalized so input not case senitive. C++ also capitalized cin>>useritem
            totalNum = products.count(word)
            total_Num_Inventory -= 1 #Checks if iterated at all, if not, prompts program to obtain another input. 
        if (temp_String != v and total_Num_Inventory == total_Num_Inventory_Count):
            return -1 

    
    
    return totalNum


def read_AND_Write_File():

    # read_And_Write_File function takes information from text file counts product and sorts/counts items.
    # It then takes the sorted and counted items and writes to a dat file and will then output a histogram
    # of item frequency in frequency.dat

    ticket = open("CS210_Project_Three_Input_File.txt")
    data = open("frequency.dat", "w")
    products = ticket.read().split() #Products creates an object that holds each line info from ticket object.
    unique_Product = sorted(set(products)) #unique_Products sorts the items.


    #Writes data from uniqueProduct to frequencey.dat file. 
    for word in unique_Product:
        data.write(word)
        data.write(" ")
        data.write(str(products.count(word))) 
        data.write("\n")
    
    data.close() #Closes file to prevent memory leak. 

    histo_data = open("frequency.dat", "r") #histo_data reads frequency.dat file
    product_data = histo_data.readlines() 


    #Nested loop variables. 
    temp_freq = 0
    temp_product = ""

    #Loop reads and prepares data from frequency.dat file for histogram output.
    for line in product_data:
        temp_int = 0
        temp_string = line.split() 
        for word in temp_string:
            temp_int += 1
            if (temp_int == 1):
                temp_product = word 
                numLetters = len(word) 
                charPrint = "*"
                lengthPrint = 70 - numLetters
                print("*******************************************************************************")
                print("*                                                                             *")
                print("*" + "ITEM: ", temp_product, '{1:>{0}}'.format(lengthPrint, charPrint))
                # Used for output formating. 
                
            if (temp_int == 2):
                temp_freq = int(word) #temp_freq is the frequency of product
        
        #Creates Histogram EXAMPLE: HISTOGRAM: Onions ****. Iterates and printes a + for each 
        #occurance an item is in the data set. Function print_histo() defined and prints "+" value for histogram.
        #variables charPrint, numLetters, lengthPrint used to format display and correct amount of whitespace.
        print("*                                                                             *")
        def print_histo():               
         for i in range(temp_freq):
            print("+", end = "")
        print("*HISTOGRAM: ", end = "+")
        print_histo()
        numLetters = int(word) 
        charPrint = "*"
        lengthPrint = 66 - numLetters
        print('{1:>{0}}'.format(lengthPrint, charPrint))
        
        print("*                                                                             *")
        print("*******************************************************************************")
       

        