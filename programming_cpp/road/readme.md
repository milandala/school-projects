# Road

A road of length N (1<=N<=1000) is being renovated  because of its ill state. The renovation is done in M (1<=M<=) sections. For each renovation done we know 
the start (K_i) and the end of the section (V_i) that was renovated (0<=K_i<V_i<=N).

## Exercise
Write a program that prints
1. The length of the shortest renovated section.
2. The start of the first section which was renovated at least 3 times (if none exists, print -1).
3. How many more km's should be renovated in addition, so the whole road is renovated. 
4. The length of the longest section where there were _no_ renovations at all.

## Input
In the first line of the standard input the length of the road (N) and the number of times there was a renovation (M) can be found.
Under that, line by line there are the start (K_i) and end (V_i) points of each renovation.

## Output
The answer of each question should be printed to the standard output line by line.

## Example
| Input | Output |
|-------|--------|
| 100 5 | 1      |
| 0 10  | 4      |
| 0 5   | 63     |
| 75 95 | 58     |
| 4 17  |        |
| 13 14 |        |



