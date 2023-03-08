# ice-cream_parlor_management_system

#### introduction
ice cream parlour management system is a command line based program implemented using c language. the program has a modal interface, which means that you the user can select, which mode to work in based on the requirement. 
for example: 
- checking the stock, and the variety of icecreams
- making transactions in the transaction mode
- restocking icecreams in restock mode
- summarise todays sales and expences in the summarise mode
.
.
.


#### description

```
***************************************************
welcome                                           *
                                                  *
0. to exit
1. transaction mode
2. restock mode
3. summarise mode
4. check stock mode

use : /*  user enters mode based on the requirement */
```


#### module description

> all the modes are implemented in seperate modules.

###### main module
- it is the junction for all the modules

###### transaction mode
- this mode is used when you sell icecreams.
- it keeps track of money with you, and validates whether the transaction for that icecream is doable or not
- if icecream is not in stock, it prompts accordingly
- else if the icecream is in stock, it  reduces one from the stock count and adds money to the total amount

###### restock mode
- it comes into play when you restock the icecreams
- it increases the count of the variety if available, else it adds a new variety
- all the data is stored in a file (csv most probably) and at the end shows the amount you have to pay
- if the amount is more than what you can pay, you can drop some stock to keep it in budget
- after paying, the icecreams are added to the main database (file) for you to be able to list them and sell them
- linklists or binary trees will be used to store stock data.

###### summarise mode
- it prints how many of which variety icecreams are left
- how much electricity is consumed till date (if bill for electircity is not paid)

###### data module
- it will be responsibele for all the file handling and data transactions


