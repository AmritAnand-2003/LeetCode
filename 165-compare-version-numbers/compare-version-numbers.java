class Solution {
    public int compareVersion(String version1, String version2) {
        String[] parts1 = version1.split("\\.");
        String[] parts2 = version2.split("\\.");
        int len = Math.min(parts1.length, parts2.length);
        for(int i = 0;i < len; i++) {
            int num1 = Integer.parseInt(parts1[i]);
            int num2 = Integer.parseInt(parts2[i]);
            if(num1 > num2){
                return 1;
            }
            else if(num1 < num2) {
                return -1;
            }
        }
        if(parts1.length > parts2.length) {
            for(int i = parts2.length; i < parts1.length; i++) {
                if(Integer.parseInt(parts1[i]) > 0){
                    return 1;
                }
            }
        }
        else if(parts1.length < parts2.length) {
            for(int i = parts1.length; i < parts2.length; i++) {
                if(Integer.parseInt(parts2[i]) > 0){
                    return -1;
                }
            }
        }
        return 0;
    }
}