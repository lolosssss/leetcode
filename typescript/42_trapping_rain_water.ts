function trap(height: number[]): number {
    if (height.length <= 2) {
        return 0;
    }

    let left = 0, right = height.length - 1;
    let currentHeight = 1;
    let areaAll = 0;
    let areaBar = 0;

    while (left < right) {
        while (left < right && height[left] < currentHeight) {
            areaBar += height[left++]
        }

        while (left < right && height[right] < currentHeight) {
            areaBar += height[right--]
        }

        if (left >= right) {
            break;
        }

        areaAll += (right - left + 1);
        currentHeight++;
    }

    if (left === right) {
        if (height[left] >= currentHeight) {
            areaAll += height[left] + 1 - currentHeight;
        }

        areaBar += height[left];
    }

    return areaAll - areaBar;
}