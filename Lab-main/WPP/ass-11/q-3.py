import pandas as pd

asking_prices = pd.Series([25000, 18000, 22000, 15000, 17000])
fair_prices = pd.Series([24000, 20000, 21000, 16000, 18000])

good_deals = asking_prices < fair_prices

good_deal_indices = list(good_deals[good_deals].index)
print("Good deal indices:", good_deal_indices)
