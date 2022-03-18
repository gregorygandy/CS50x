from cs50 import get_float

change_owed = get_float("Change owed: ")

while change_owed < 0:
    change_owed = get_float("Change owed: ")

quarters = change_owed // 0.25
quarter_remainder = round(change_owed % 0.25, 2)

dimes = quarter_remainder // 0.10
dimes_remainder = round(quarter_remainder % 0.10, 2)

nickels = dimes_remainder // 0.05
nickels_remainder = round(dimes_remainder % 0.05, 2)

pennies = nickels_remainder // 0.01

coins = int(quarters + dimes + nickels + pennies)

print(coins)