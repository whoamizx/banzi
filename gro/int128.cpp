// int128的输入输出
namespace fastio
{
    struct reader
    {
        template <typename T>
        reader &operator>>(T &x)
        {
            char c = getchar();
            short f = 1;
            while (c < '0' || c > '9')
            {
                if (c == '-')
                    f *= -1;
                c = getchar();
            }
            x = 0;
            while (c >= '0' && c <= '9')
            {
                x = (x << 1) + (x << 3) + (c ^ 48);
                c = getchar();
            }
            x *= f;
            return *this;
        }
    } cin;
    struct writer
    {
        template <typename T>
        writer &operator<<(T x)
        {
            if (x == 0)
                return putchar('0'), *this;
            if (x < 0)
                putchar('-'), x = -x;
            static int sta[45];
            int top = 0;
            while (x)
                sta[++top] = x % 10, x /= 10;
            while (top)
                putchar(sta[top] + '0'), --top;
            return *this;
        }
    } cout;
};
#define cin fastio::cin
#define cout fastio::cout


#define int __int128
inline void read(int &n){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    n=x*f;
}
inline void print(int n){
    if(n<0){
        putchar('-');
        n*=-1;
    }
    if(n>9) print(n/10);
    putchar(n % 10 + '0');
}
#undef int
