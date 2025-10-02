class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int result=numBottles;
        int empty=numBottles;

        while(empty>=numExchange){
            int newB=empty/numExchange;
            result=result+newB;
            empty=newB+(empty%numExchange);
        }

        return result;
    }
}
