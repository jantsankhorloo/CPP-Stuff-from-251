# CuckooHashing

Cuckoo hashing uses 2 tables, T1 and T2, and 2 functions h1(x) = x mod r and h2(x) = x mod (r − 1).

The format of the inputfile.txt has the following structure:
1
r m
a b
a b
a b
a b
...

Where 1 indicates that the Cuckoo Hashing part will be executed, r is a positive integer that
indicates the length of the tables and m is a positive integer that indicates the maximum number
of loops. For each tuple ( a b ), a is the instruction to perform and b is the number for the required
instruction. The possible values for a are “ i ” for insert, “ r ” for remove and “ l ” for lookup. The
values of b are positive integer numbers.
The program has to write the following outputs:

● Every time an element x is inserted in T i [h i (x)] (during insertion, rehashing, and element
swapping) then write the element and where it is in which table; i.e., if x = 2 and it was
inserted in table T 1 at position h 1 (2) = 11 then the output is “2 in T1[11]”. If x was inserted
into an empty cell then add an exclamation mark “!” at the end of the output line. If x is
already on either T 1 or T 2 then the output is “2 already in T1[11]”.

● When x is removed using the remove function then write “2 out T1[11]”; i.e., if x = 2 and
is was removed from table T 1 and position h 1 (2) = 11 . If x is not removed because it isn’t
on neither T1 or T2 then write “no out 2”.

● When x is looked up and it was found then write where; i.e., if x = 2 and it is in T 1 at
position h 1 (2) = 11 then the output is “2 at T1[11]”. If x is not found then write “no 2”. i.e.,
if x = 2 is neither in T 1 nor T 2 then write “no 2”.

● If the MaxLoop value is reached then write “maxloop reached”.
