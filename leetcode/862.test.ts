import { shortestSubarray } from "./862";

describe("shortestSubarray", () => {
  test("Case 1", () => {
    expect(shortestSubarray([1], 1)).toBe(1);
  });

  test("Case 2", () => {
    expect(shortestSubarray([1, 2], 4)).toBe(-1);
  });

  test("Case 3", () => {
    expect(shortestSubarray([2, -1, 2], 3)).toBe(3);
  });

  test("Testcase 6", () => {
    expect(shortestSubarray([77, 19, 35, 10, -14], 19)).toBe(1);
  });

  test("Testcase 21", () => {
    expect(shortestSubarray([48, 99, 37, 4, -31], 140)).toBe(2);
  });

  test("Testcase 25", () => {
    expect(shortestSubarray([56, -21, 56, 35, -9], 61)).toBe(2);
  });

  test("Testcase 29", () => {
    expect(shortestSubarray([17, 85, 93, -45, -21], 150)).toBe(2);
  });

  test("Testcase 33", () => {
    expect(shortestSubarray([56, -21, 56, 35, -9], 61)).toBe(2);
  });

  test("Testcase 62", () => {
    expect(shortestSubarray([84, -37, 32, 40, 95], 167)).toBe(3);
  });

  test("Testcase 83", () => {
    expect(shortestSubarray([-28, 81, -20, 28, -29], 89)).toBe(3);
  });
});
