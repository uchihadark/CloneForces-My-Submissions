from submitForces import SF

if __name__ == "__main__":
    time_range = (3600 * 24) * 7  # one week
    SF(time_range)()