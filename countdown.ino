void print_time() {
  time_s--;
  if (time_s < 0) {
    time_s = 59;
    time_m--;
    if (time_m < 0) {
      time_m = 59;
      time_h--;
      if (time_h < 0) {
        time_h = 59;
      }
    }
  }
}
