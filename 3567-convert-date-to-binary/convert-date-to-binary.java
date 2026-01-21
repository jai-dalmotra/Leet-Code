class Solution {
    public String convertDateToBinary(String date) {

        String ans ="";

        String year = Integer.toBinaryString(
        Integer.parseInt(date.substring(0, 4))
        );

        String month = Integer.toBinaryString(
        Integer.parseInt(date.substring(5, 7))
        );

        String day = Integer.toBinaryString(
        Integer.parseInt(date.substring(8, 10))
        );

        ans = year+"-"+month+"-"+day;
        // date.substring(5,7);
        // date.substring(8,10);

        return ans;
        
    }
}