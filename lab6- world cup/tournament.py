# Simulate a sports tournament



import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    #if len(sys.argv) != 2:
        #sys.exit("Usage: python tournament.py FILENAME")

    teams = [{'team': 'Uruguay', 'rating': 976}, {'team': 'Portugal', 'rating': 1306}, {'team': 'France', 'rating': 1166}, {'team': 'Argentina', 'rating': 1254}, {'team': 'Brazil', 'rating': 1384}, {'team': 'Mexico', 'rating': 1008}, {'team': 'Belgium', 'rating': 1346}, {'team': 'Japan', 'rating': 528}, {'team': 'Spain', 'rating': 1162}, {'team': 'Russia', 'rating': 493}, {'team': 'Croatia', 'rating': 975}, {'team': 'Denmark', 'rating': 1054}, {'team': 'Sweden', 'rating': 889}, {'team': 'Switzerland', 'rating': 1179}, {'team': 'Colombia', 'rating': 989}, {'team': 'England', 'rating': 1040}]

    # TODO: Read teams into memory from file

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(N):
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 0


    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    winningTeams = simulate_round(teams)

    if len(winningTeams) == 1:
        return winningTeams[0]
    else:
        simulate_tournament(winningTeams)


if __name__ == "__main__":
    main()
