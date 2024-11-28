package leetcode.prob67;

class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int aIdx = a.length() - 1;
        int bIdx = b.length() - 1;

        int before = 0;
        while (aIdx >= 0 && bIdx >= 0) {
            int aInt = a.charAt(aIdx) - '0';
            int bInt = b.charAt(bIdx) - '0';

            int curr = (aInt + bInt + before) % 2;
            before = (aInt + bInt + before) / 2;

            sb.append(curr);
            aIdx--;
            bIdx--;
        }

        while (aIdx >= 0) {
            int aInt = a.charAt(aIdx) - '0';

            int curr = (aInt + before) % 2;
            before = (aInt + before) / 2;

            sb.append(curr);
            aIdx--;
        }

        while (bIdx >= 0) {
            int aInt = b.charAt(bIdx) - '0';

            int curr = (aInt + before) % 2;
            before = (aInt + before) / 2;

            sb.append(curr);
            bIdx--;
        }

        if (before == 1) sb.append(before);

        sb.reverse();
        return sb.toString();
    }

    public static void main(String[] args) {

    }
}
