# Keylog

A common security method used for authentication is to ask a user for specific random characters from 
a passcode, rather than entering the passcode in full. For example, if the passcode was 531278, a user may be 
asked for the 2nd, 3rd, and 5th characters; and their expected reply would be: 317

This program accepts a file of consisting of these 3 digit sequences that were successful and then calculates the full password.

## Usage guide

- Sequences can be in any formatted in any way, characters other than numbers will be ignored.
- Input file should be in .txt.
- Duplicate digits within the same 3 digit sequence are not allowed.

## IMPORTANT

I have implemented some features from the C++20, namely the unordered_set.contains() method fairly extensively. This can potentially be refactored by instead using 
unordered_set.count(). (as the result will always be 1 or 0 since each key is unique).
