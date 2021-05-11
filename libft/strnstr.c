#include "libft.h"

int main() {
	char *in1;		// 첫 번째 인자로 넘길 문자열
	char *in2;		// 두 번째 인자로 넘길 문자열
	size_t num;		// 세 번째 인자로 넘길 size_t
	char *temp1;
	char *temp2;	// NULL 값 입력시 원래 자리 회복을 위한 변수
	in1 = (char *)malloc(sizeof(char) * 100);
	in2 = (char *)malloc(sizeof(char) * 100);
	temp1 = in1;
	temp2 = in2;
	while (1)
	{
		printf("usage:\t<in1>\t<in2>\t<num>\n");
		scanf("%s %s %ld", in1, in2, &num);
		printf("%ld\n", num);
		if (ft_strncmp(in1, "\\0", 5) == 0)
			ft_strlcpy(in1, "", 1);		// "\0" 가 오면 in1을 빈문자열로 치환
		if (ft_strncmp(in2, "\\0", 5) == 0)
			ft_strlcpy(in2, "", 1);		// "\0" 가 오면 in2를 빈문자열로 치환
		if (ft_strncmp(in1, "NULL", 10) == 0)
			in1 = 0;		// "NULL" 이 오면 in1을 NULL로 치환
		if (ft_strncmp(in2, "NULL", 10) == 0)
			in2 = 0;		// "NULL" 이 오면 in2를 NULL로 치환
		printf("-----input----\n");
		printf("in1:\t#%s#\n", in1);	// input 확인
		printf("in2:\t#%s#\n", in2);
		printf("num:\t#%ld#\n", num);
		printf("----result----\n");		// result 비교
		printf("strnstr:\t#%s#\n", strnstr(in1, in2, num));
		printf("ft_strnstr:\t#%s#\n", ft_strnstr(in1, in2, num));
		printf("--------------\n");
		if (!in1 || !in2)
		{
			in1 = temp1;
			in2 = temp2;
		}
	}
}
