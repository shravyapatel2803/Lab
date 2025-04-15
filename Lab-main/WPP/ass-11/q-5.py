import pandas as pd
from itertools import product

data = {
    'date': pd.to_datetime([
        '2024-01-10', '2024-01-10', '2024-01-11', '2024-02-15',
        '2024-02-20', '2024-02-20', '2024-03-05'
    ]),
    'artist': ['A', 'B', 'A', 'A', 'C', 'C', 'B'],
    'venue': ['X', 'Y', 'X', 'Y', 'Y', 'Z', 'X']
}
df = pd.DataFrame(data)
df['year_month'] = df['date'].dt.to_period('M')

grouped = df.groupby(['year_month', 'artist', 'venue']).size()

artists = df['artist'].unique()
venues = df['venue'].unique()
all_combos = pd.MultiIndex.from_product(
    [df['year_month'].unique(), artists, venues],
    names=['year_month', 'artist', 'venue']
)

grouped_full = grouped.reindex(all_combos, fill_value=0)

wide = grouped_full.unstack(['artist', 'venue']).fillna(0).astype(int)
print(wide)
