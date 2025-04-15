import pandas as pd
from datetime import datetime

dt1 = pd.to_datetime('2012-01-15')
print("a) Date time object for Jan 15, 2012:", dt1)

dt2 = pd.to_datetime('2012-01-15 21:20')
print("b) Specific date and time of 9:20 PM:", dt2)

dt3 = pd.Timestamp.now()
print("c) Local date and time:", dt3)

dt4 = pd.to_datetime('2012-01-15').date()
print("d) A date without time:", dt4)

dt5 = pd.Timestamp.now().date()
print("e) Current date:", dt5)

dt6 = pd.Timestamp('2012-01-15 21:20:00').time()
print("f) Time from a date time:", dt6)

dt7 = pd.Timestamp.now().time()
print("g) Current local time:", dt7)
