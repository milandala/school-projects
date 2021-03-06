# Weather

In a weather forecast we've received the minimum and maximum temperature for the following N days.

## Exercise
Write a program that prints
1. The number of days when it will freeze.
2. The index of the day when the difference between minimum and maximum temperature is the greatest (if more exists, the index of the first one).
3. The index of a day when the current maximum is lower than the minimum of the previous day (if more exists, the index of the first one, if none exists, the first one).
4. The sum and indices of the days where freeze and melting are both expected.

## Input
In the first line of the standard input the number of the days (N) can be found. Under that, line by line there are the daily minimum and maximum temperature.

## Output
The answer of each question should be printed to the standard output line by line seperated by '#'.

## Example
| Input | Output |
|-------|--------|
| 6     | #      |
| -5 5  | 4      |
| 0 10  | #      |
| -5 -3 | 1      |
| -5 0  | #      |
| 2 10  | 3      |
| 10 13 | 2 1 2  |


