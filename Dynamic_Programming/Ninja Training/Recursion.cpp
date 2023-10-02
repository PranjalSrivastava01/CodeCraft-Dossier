int fun(int day,int last,vector<vector<int>> &points)
{
    if(day==0)
    {
        int maxi=0;
        for(int i=0;i<3;i++)
        {
          if(i!=last) maxi=max(maxi,points[0][i]);
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
          int point=points[day][i]+fun(day-1,i,points);
          maxi=max(point,maxi);
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    return fun(n-1,3,points);
}