import pandas as pd

s = pd.Series(['X', 'Y', 'T', 'Aaba', 'Baca', 'CABA', None, 'bird', 'horse', 'dog'])

upper_case = s.str.upper()
print("Upper case:\n", upper_case)

lower_case = s.str.lower()
print("\nLower case:\n", lower_case)

lengths = s.str.len()
print("\nLength of each string:\n", lengths)
