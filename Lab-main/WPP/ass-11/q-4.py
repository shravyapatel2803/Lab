import pandas as pd

data = {
    'John': [True, False, True, True, False, True, False, False, True, False],
    'Judy': [True, False, False, True, True, True, False, True, True, False]
}
df = pd.DataFrame(data)

party_days = df['John'] & df['Judy']

days_til_party = (~party_days)[::-1].cumsum()[::-1] - (~party_days).cumsum()
days_til_party[party_days] = 0  # Party today → 0

df['days_til_party'] = days_til_party
print(df)
