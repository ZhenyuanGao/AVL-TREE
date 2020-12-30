# AVL-TREE
Designed a self-balancing AVL tree.

Implement an AVL tree whose node values are integers.  It should be able to support three operations: insert, find, and delete.  Implement any replacement operations to use the predecessor.

Input:
a sequence of commands to stdin that insert, find, or delete an integers.

Output:
for each command executed, a list of the node-values within the tree that are traversed to find the initial position in the tree to begin to process the command.
for insert it will be the list of values traversed before initially inserting the new value, followed by the value inserted
for find, it will be the list of nodes traversed before finding the value we are looking for or before being able to assert the value is not present in the tree.  Asserts whether value was found or not.
for delete, it will be the list of nodes traversed before finding the node to be deleted or before being able to assert the value is not present in the tree.  Asserts whether the node to be deleted was found or not.

Example:

	input:
insert 50
insert 25
insert 10
insert 5
insert 7
insert 3
insert 30
insert 20
insert 8
insert 15
find 10
find 12
delete 4
delete 20
find 22
delete 50
find 30
delete 10
find 7

output:
50 (inserted)
50 25 (inserted)
50 25 10 (inserted)
25 10 5 (inserted)
25 10 5 7 (inserted)
25 7 5 3 (inserted)
7 25 50 30 (inserted)
7 25 10 20 (inserted)
7 25 10 8 (inserted)
7 25 10 20 15 (inserted)
10 (found)
10 25 20 15 (not found!)
10 7 5 3 (not found!)
10 25 20 (deleted)
10 25 15 (not found!)
10 25 50 (deleted)
10 25 30 (found)
10 (deleted)
8 5 7 (found)

