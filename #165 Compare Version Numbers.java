public class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1s = version1.split("\\.");
        String[] v2s = version2.split("\\.");
        int i = 0;
        for (; i < v1s.length && i < v2s.length; i ++) {
            int v1 = Integer.parseInt(v1s[i]);
            int v2 = Integer.parseInt(v2s[i]);
            if (v1 > v2) {
                return 1;
            }
            if (v2 > v1) {
                return -1;
            }
        }
        if (i < v1s.length) {
            for (;i < v1s.length;i++) {
                if (Integer.parseInt(v1s[i]) != 0) {
                    return 1;
                }
            }
        }
        if (i < v2s.length) {
            for (;i < v2s.length;i++) {
                if (Integer.parseInt(v2s[i]) != 0) {
                    return -1;
                }
            }
        }
        return 0;
    }
}
