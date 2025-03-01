class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> name(int n);
        for(int i=1;i<=n;i++)
        {
            if(i%3==0&&i%5!=0)
            {
                name.push_back("Fizz");
            }
            else if(i%5==0&&i%3!=0)
            {
                name.push_back("Buzz");
            }
            else if(i%3==0&&i%5==0)
            {
                name.push_back("FizzBuzz");
            }
            else
            {
                name.push_back(i);
            }
        }
    }
};
