class FoodRatings {
    class Pair implements Comparable<Pair>{
        String food;
        int rating;
        public Pair(String food,int rating){
            this.food=food;
            this.rating=rating;
        }
        public int compareTo(Pair p){
            if(this.rating!=p.rating){
                return p.rating-this.rating;
            }
            return this.food.compareTo(p.food);
        }
    }
    Map<String,String> foodCuisine;
    Map<String,Integer> foodRating;
    Map<String,TreeSet<Pair>> cuisineFood;

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        foodCuisine=new HashMap<>();
        foodRating=new HashMap<>();
        cuisineFood=new HashMap<>();

        for(int i=0;i<foods.length;i++){
            String f=foods[i];
            String c=cuisines[i];
            int r= ratings[i];
            foodCuisine.put(f,c);
            foodRating.put(f,r);
            cuisineFood.putIfAbsent(c,new TreeSet<>());
            cuisineFood.get(c).add(new Pair(f,r));
        }
    }
    
    public void changeRating(String food, int newRating) {
        String c=foodCuisine.get(food);
        int oldRating=foodRating.get(food);
        foodRating.put(food,newRating);
        cuisineFood.get(c).remove(new Pair(food,oldRating));
        cuisineFood.get(c).add(new Pair(food,newRating));
    }
    
    public String highestRated(String cuisine) {
        return cuisineFood.get(cuisine).first().food;
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */
