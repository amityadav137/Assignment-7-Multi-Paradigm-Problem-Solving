class StatisticsCalculator:
    def __init__(self, data):
        if not data:
            raise ValueError("Data list cannot be empty.")
        self.data = sorted(data)

    def mean(self):
        return sum(self.data) / len(self.data)

    def median(self):
        n = len(self.data)
        mid = n // 2
        if n % 2 == 0:
            return (self.data[mid - 1] + self.data[mid]) / 2
        return self.data[mid]

    def mode(self):
        counts = {}
        for num in self.data:
            counts[num] = counts.get(num, 0) + 1
        max_count = max(counts.values())
        return [num for num, cnt in counts.items() if cnt == max_count]

if __name__ == "__main__":
    nums = input("Enter integers separated by spaces: ").split()
    data = list(map(int, nums))
    calc = StatisticsCalculator(data)
    print(f"Mean: {calc.mean():.2f}")
    print(f"Median: {calc.median():.2f}")
    print(f"Mode: {' '.join(map(str, calc.mode()))}")
