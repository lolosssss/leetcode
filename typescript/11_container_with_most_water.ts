function maxArea(height: number[]): number {
  let head = 0,
    tail = height.length - 1;
  let max = 0;
  while (head < tail) {
    let area = Math.min(height[head], height[tail]) * (tail - head);
    if (area > max) max = area;
    if (height[head] <= height[tail]) {
      head++;
    } else {
      tail--;
    }
  }
  return max;
}
