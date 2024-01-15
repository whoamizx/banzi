struct jie
{
    int dis, i, j;
    jie(int _dis, int _i, int _j)
    {
        dis = _dis;
        i = _i;
        j = _j;
    }
    bool operator<(const jie A) const
    {
        return dis < A.dis;
    }
};