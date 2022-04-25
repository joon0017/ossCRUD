#include "manager.h"
#include <stdlib.h>
int selectMenu(){
    int menu;
    printf("\n*** 제품 관리 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
void listProduct(Product *p,int count){

    printf("\nNo. Name          weight price\n");
    printf("================================\n");
    for(int i=0; i<count; i++){
        if( p[i].weight == -1 || p[i].price == -1 ) continue;
        printf("%2d.", i+1);
        readProduct(&p[i]);
    }
    printf("\n");
}

int selectDataNo(Product *p, int count){
    int no;
    listProduct(p,count);
    printf("번호는 (취소:0)?");
    scanf("%d",&no);
    getchar();
    return no;
}

//배열데이터를 파일에 저장하는 함수
void saveData(Product p[], int count){
	FILE* fp;

	//중량 가격 제품명
	fp= fopen("product.txt","wb");
	for(int i=0;i<count;i++){
		fputs("\n",fp);
		fputs(p[i].name,fp);
		fputs("\n",fp);
		char temp[10];
		sprintf(temp, "%d", p[i].weight);
		fputs(temp,fp);
		fputs("\n",fp);
		char tempp[10];
		sprintf(tempp,"%d",p[i].price);
		fputs(tempp,fp);
	}
	fclose(fp);
	printf("저장됨!\n");
}

//파일에서 데이터 불러오는 함수
int loadData(Product *p){
	int count=0;
	FILE* fp;
	fp= fopen("product.txt","r");
	if (fp == NULL) {
		printf("파일 조회 실패\n");
		return 0;
	}
	int lc = 0;
	while(!feof (fp)){
		if (lc%3==0) {
			fgetc(fp);
			fscanf(fp, "%[^\n]s",p[count].name); 
		}
		else{
			char temp[10];
			fscanf(fp,"%s",temp);
			int tmpint=0;
			tmpint = atoi(temp);
			if (lc%3==1) p[count].weight = tmpint;
			else {
				p[count].price = tmpint;
				count++;
			}
		}
		lc++;
	}
	printf("=> 로딩 성공!\n");
	return count;
}

