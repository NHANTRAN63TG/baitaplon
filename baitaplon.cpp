#include<stdio.h>
#include <string.h>
#include <math.h>
 
typedef struct noidung{
	char ID[10];
	char tensan[20];
	char diachi[50];
	char giohd[10];
	int loai;
	long gia;
	char sdt[11];
	float A[25];
	int sl;
	float gio;
	float tien;
}noidung;

noidung *nhapnoidung(int y,int m2,char ID1[10],char tensan1[20],char giohd1[10],int loai1,long gia1,char diachi1[50],char sdt1[11],int sl1,float A1[25],float gio1,float tien1){
	noidung *nd=new noidung;
	if(m2==0&&y==0){
         getchar();
         printf("MA SAN: ");
         fgets(nd->ID, sizeof(nd->ID), stdin);
	     printf("ten san: ");
         fgets(nd->tensan, sizeof(nd->tensan), stdin);
	     printf("dia chi: ");
         fgets(nd->diachi, sizeof(nd->diachi), stdin);
         printf("gio hoat dong(vd:7h-10h): ");
         fgets(nd->giohd, sizeof(nd->giohd), stdin);
         printf("so dien thoai lien lac: ");
	     fgets(nd->sdt, sizeof(nd->sdt), stdin);
         printf("loai san: "); scanf("%d",&nd->loai);
         printf("gia tien mot gio:"); scanf("%d",&nd->gia);
         nd->gio=0;
	     nd->tien=0;
	     nd->sl=0;
	     return nd;
    }
    else if(m2==0&&y==1&&sl1==0){
    	 strcpy(nd->ID, ID1);
         strcpy(nd->tensan, tensan1);
         strcpy(nd->diachi, diachi1);
         strcpy(nd->giohd, giohd1);
         strcpy(nd->sdt, sdt1);
         nd->loai=loai1;
         nd->gia=gia1;
    	 nd->gio=0;
	     nd->tien=0;
	     nd->sl=0;
	     return nd;
	}
    else if(m2==0&&y==1&&sl1>0){
		 strcpy(nd->ID,ID1);
         strcpy(nd->tensan,tensan1);
         strcpy(nd->diachi,diachi1);
         strcpy(nd->giohd,giohd1);
         strcpy(nd->sdt,sdt1);
         nd->loai=loai1;
         nd->gia=gia1;
	     nd->sl=sl1;
		 for(int i=0;i<sl1*2;i=i+2){	
     	 nd->A[i]=A1[i];
         nd->A[i+1]=A1[i+1];
 	     }
         nd->gio=gio1;
    	 nd->tien=tien1;
    	 return nd;
         }
	else if(m2==1&&y==1){
		 strcpy(nd->ID,ID1);
         strcpy(nd->tensan,tensan1);
         strcpy(nd->diachi,diachi1);
         strcpy(nd->giohd,giohd1);
         strcpy(nd->sdt,sdt1);
         nd->loai=loai1;
         nd->gia=gia1;
	     printf("so nguoi dat san: "); scanf("%d",&nd->sl);
	     int stt=1;
		 for(int i=0;i<(nd->sl)*2;i=i+2){	
		 printf("NGUOI DAT SAN THU %d: ",stt);
    	 printf("??H?? den ??H??\n");
    	 scanf("%f",&nd->A[i]);
    	 scanf("%f",&nd->A[i+1]);
    	 stt++;
	     }
    	 float gio11=0;
    	 float gio22=0;
    	 for(int i=0;i<(nd->sl)*2;i=i+2){
    	 float a1=trunc(nd->A[i]);
    	 float a2=trunc(nd->A[i+1]);
    	 float a3=a2-a1;
    	 float a4=(nd->A[i+1])-(nd->A[i])-a3;
    	 gio11=gio11+(nd->A[i+1])-(nd->A[i]);
    	 gio22=gio22+a3*60+a4*100;
	     }
         gio22=gio22/60;
         nd->gio=gio11;
    	 nd->tien=gio22*(nd->gia);
    	 return nd;
         }
}			

typedef struct Node{
	noidung *data;
	Node *next;
}Node;

typedef struct List{
	Node *head;
	Node *tail;
	int size;
    List();
	Node *createNode(noidung *nd);
	bool isEmpty();
	void addLast(noidung *nd);
	void addFirst(noidung *nd);
	void insert(noidung *nd,int pos);
	void deleteFirst();
	void deleteLast();
	void deleteAtPosition(int pos);
	void SOSANCONHD();
	void print();
	void print1();
	void print2();
	void Sapxep();
	void Sapxep1();
	void Loc();
	int checkID();
	void saveFile(int tam);
	int openFile();
	void nhapdsdatsan(int dem);
	void saveFile1(int tam);
	void openFile1();
}List;

List::List(){
	head=tail=NULL;
	size =0;
}

Node* List::createNode(noidung *nd){
	Node *p= new Node();
	p->data=nd;
	p->next=NULL;
	return p;
                                 }
                                 
void List::addFirst(noidung *nd){
	Node *p = createNode(nd);
	if(head==NULL){
		head=tail=p;
	}
	else{
		p->next=head;
		head=p;
	}
	size++;
}

void List::insert(noidung *nd, int pos){
	Node *p=createNode(nd);
	if(head==NULL)
		head=tail=p;
	else{
		if(pos>size+1)
			printf("Vuot danh sach");
		else if(pos==1)
			addFirst(nd);
		else if(pos==size+1)
			addLast(nd);
		else{
			Node *a=head;
			for(int i=1;i<pos-1;i++){
				a=a->next;
			}
			p->next=a->next;
			a->next=p;
			size++;
		}
	}
}

void List::addLast(noidung *nd){
	Node *p=createNode(nd);
	if(head==NULL){
		head=tail=p;
	}
	else{
		tail->next=p;
		tail=p;
	}
	size++;
} 

void List::SOSANCONHD(){
	printf("SO SAN BONG CON HOAT DONG LA: %d\n",size);
	printf("DANH SACH SAN CON HOAT DONG:\n");
}

void List::deleteFirst(){
	if(head==NULL)
		printf("Danh sach dang rong");
	else{
		Node *a=head;
		head=head->next; 
		free(a);  
		size--;
	}
}

void List::deleteLast() {
    if (head == NULL) {
        printf("Danh sach dang rong\n");
        return;
    }
    if (head->next == NULL) {  
        delete head;
        head = tail = NULL;
        size--;
    } else {
        Node *a = head;
        while (a->next != tail) { 
            a = a->next;
        }
        delete tail;      
        tail = a;         
        tail->next = NULL;
		size--; 
    }
    
}

void List::deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    if (pos < 1 || pos > size) {
        printf("Vi tri khong hop le! Vui long nhap lai.\n");
        return;
    }
    if (pos == 1) {
        deleteFirst();
        return;
    }
    if (pos == size) {
        deleteLast();
        return;
    }
    Node* a = head;
    Node* b = NULL;

    for (int i = 1; i < pos; i++) {
        b = a;
        a = a->next;
    }
    b->next = a->next;
    delete a;
    size--;
    printf("Da xoa phan tu o vi tri %d\n", pos);
}
// hàm ki?m tra r?ng 
bool List::isEmpty(){
	Node* head;
    return head == NULL;
}

int List::checkID(){
	char id[10];
	int stt=0;
	int temp=0;
	scanf("%s",&id);
	for( Node *i=head;i!=NULL;i=i->next){
		char *result = strstr(i->data->ID, id);
		if(result){
			 temp=temp+1;
			 stt=stt+1;
		     break;
		}
		stt=stt+1;
	}
	if(temp==0){
	  return 0;	
	}
	else
	return stt;
}

void List::Sapxep(){
	    int g;
		printf("GIA TANG DAN NHAN PHIM 1\n");
	    printf("GIA GIAM DAN NHAN PHIM 2\n");
	    scanf("%d",&g);
	    Node *temp=new Node;
		if(g==1){
    	for( Node *a=head;a!=NULL;a=a->next){	
    	for( Node *b=a->next;b!=NULL;b=b->next){	
    	if((a->data->gia)>(b->data->gia)){
		temp->data = a->data;
        a->data = b->data;
        b->data = temp->data;
	    }
     }
  }
}
	    else if(g==2){
    	for( Node *a=head;a!=NULL;a=a->next){	
    	for( Node *b=a->next;b!=NULL;b=b->next){	
    	if((a->data->gia)<(b->data->gia)){
		temp->data = a->data;
        a->data = b->data;
        b->data = temp->data;
	    }
      }
    }
}
    else
    printf("khong co lua chon %d vui long chon lai\n",g);
}

void List::Sapxep1(){
	    Node *temp=new Node;
    	for( Node *a=head;a!=NULL;a=a->next){	
    	for( Node *b=a->next;b!=NULL;b=b->next){	
    	     if((a->data->loai)>(b->data->loai)){
	     	 temp->data = a->data;
             a->data = b->data;
             b->data = temp->data;
	    }
     }
  }
}

void List::Loc(){
	int a=1;
	printf("_________________________________________________________________________________________________________________________________\n");
	printf("%-4s %-11s %-20s %-10s %-5s %-10s %-50s %-10s\n","|STT","|ID","|TEN SAN","|GIO HD","|LOAI","|GIA/H","|DIA CHI","|SDT       |");
	printf("|____|___________|____________________|__________|_____|__________|__________________________________________________|__________|\n");
	for(Node *i=head;i!=NULL;i=i->next){
		if((i->data->gio)<24){
	    i->data->ID[strcspn(i->data->ID, "\n")] = '\0';	
		i->data->tensan[strcspn(i->data->tensan, "\n")] = '\0';	
		i->data->diachi[strcspn(i->data->diachi, "\n")] = '\0';	
		i->data->giohd[strcspn(i->data->giohd, "\n")] = '\0';	
		i->data->sdt[strcspn(i->data->sdt, "\n")] = '\0';
	    printf("|%-4d|%-11s|%-20s|%-10s|%-5d|%-10ld|%-50s|%-10s|\n",a,i->data->ID,i->data->tensan,i->data->giohd,i->data->loai,i->data->gia,i->data->diachi,i->data->sdt);
	    a++;	
		}
	}
	printf("|____|___________|____________________|__________|_____|__________|__________________________________________________|__________|\n\n");
}

void List::saveFile(int tam){
	FILE *file = fopen("file_btl.txt", "w");
	if (file == NULL){
        printf("khong the mo file.\n");
    }
        fprintf(file, "%d\n",tam);
    for(Node *i=head;i!=NULL;i=i->next){
    	i->data->ID[strcspn(i->data->ID, "\n")] = '\0';	
		i->data->tensan[strcspn(i->data->tensan, "\n")] = '\0';	
		i->data->diachi[strcspn(i->data->diachi, "\n")] = '\0';	
		i->data->giohd[strcspn(i->data->giohd, "\n")] = '\0';	
		i->data->sdt[strcspn(i->data->sdt, "\n")] = '\0';
    	fprintf(file, "\n%s\n",i->data->ID);
    	fprintf(file, "%s\n",i->data->tensan);
    	fprintf(file, "%s\n",i->data->diachi);
    	fprintf(file, "%s\n",i->data->giohd);
    	fprintf(file, "%s\n",i->data->sdt);
    	fprintf(file, "%d\n",i->data->loai);
    	fprintf(file, "%ld\n",i->data->gia);
    	fprintf(file, "%d\n",i->data->sl);
    	if((i->data->sl)>0){
        for(int j=0;j<(i->data->sl)*2;j=j+2){	
        fprintf(file, "%.2f ",i->data->A[j]);
		fprintf(file, "%.2f ",i->data->A[j+1]);	
		}
	 }	
	    fprintf(file, "\n%.2f",i->data->gio);
		fprintf(file, "\n%.0f\n",i->data->tien);
	}
	fclose(file);
}

int List::openFile(){
	int y=1;
	int m1,m2=0; 
	char ID1[10],tensan1[20],giohd1[10],diachi1[50],sdt1[11];
    int loai1,sl1;
    long gia1;
    float A1[25],gio1,tien1;
	FILE *file = fopen("file_btl.txt", "r");
    if(file == NULL){
        return 0;
    }
    fscanf(file,"%d\n",&m1);
	for(int i=1;i<=m1;i++){ 
	fscanf(file,"\n%s\n",&ID1);
	fscanf(file,"%s\n",&tensan1);
	fscanf(file,"%s\n",&diachi1);
	fscanf(file,"%s\n",&giohd1);
	fscanf(file,"%s\n",&sdt1);
	fscanf(file,"%d\n",&loai1);
	fscanf(file,"%ld\n",&gia1);
	fscanf(file, "%d\n",&sl1);
	if(sl1>0){
    for(int j=0;j<sl1*2;j=j+2){	
    fscanf(file, "%f ",&A1[j]);
	fscanf(file, "%f ",&A1[j+1]);	
		}
	}
	fscanf(file, "\n%f",&gio1);
	fscanf(file, "\n%f\n",&tien1);
    noidung *a=nhapnoidung(y,m2,ID1,tensan1,giohd1,loai1,gia1,diachi1,sdt1,sl1,A1,gio1,tien1);
    List::addLast(a);
    }
    fclose(file);
    return m1;
}

void List::nhapdsdatsan(int dem){
	int y=1;
	int m2=1;
	int dem1=1;
	char ID1[10],tensan1[20],giohd1[10],diachi1[50],sdt1[11];
    int loai1,sl1;
    long gia1;
    float A1[25],gio1,tien1;
    for(Node *i=head;i!=NULL;i=i->next){
         if(dem1==dem){
         strcpy(ID1,i->data->ID);
         strcpy(tensan1,i->data->tensan);
         strcpy(giohd1,i->data->giohd);
         strcpy(diachi1,i->data->diachi);
         strcpy(sdt1,i->data->sdt);
         loai1=i->data->loai;
         gia1=i->data->gia;
	     noidung *a=nhapnoidung(y,m2,ID1,tensan1,giohd1,loai1,gia1,diachi1,sdt1,sl1,A1,gio1,tien1);
	     Node *temp1 = createNode(a);
	     i->data=temp1->data;
	     break;
         }
         else
         dem1=dem1+1;
	}
}

void List::print(){
	int a=1;
	printf("_________________________________________________________________________________________________________________________________\n");
	printf("%-4s %-11s %-20s %-10s %-5s %-10s %-50s %-10s\n","|STT","|ID","|TEN SAN","|GIO HD","|LOAI","|GIA/H","|DIA CHI","|SDT       |");
	printf("|____|___________|____________________|__________|_____|__________|__________________________________________________|__________|\n");
	for(Node *i=head;i!=NULL;i=i->next){
		i->data->ID[strcspn(i->data->ID, "\n")] = '\0';	
		i->data->tensan[strcspn(i->data->tensan, "\n")] = '\0';	
		i->data->diachi[strcspn(i->data->diachi, "\n")] = '\0';	
		i->data->giohd[strcspn(i->data->giohd, "\n")] = '\0';	
		i->data->sdt[strcspn(i->data->sdt, "\n")] = '\0';
	    printf("|%-4d|%-11s|%-20s|%-10s|%-5d|%-10ld|%-50s|%-10s|\n",a,i->data->ID,i->data->tensan,i->data->giohd,i->data->loai,i->data->gia,i->data->diachi,i->data->sdt);
	    a++;
	}
	printf("|____|___________|____________________|__________|_____|__________|__________________________________________________|__________|\n\n");
}
void List::print1(){
	int a=1;
    printf("__________________________________________________________________________\n");
	printf("%-4s %-11s %-20s %-5s %-8s %-8s %-10s\n","|STT","|ID","|TEN SAN","|LOAI","|GIA/H","|SO GIO","|THANH TIEN|");
	printf("|____|___________|____________________|_____|________|________|__________|\n");
	for(Node *i=head;i!=NULL;i=i->next){
		i->data->ID[strcspn(i->data->ID, "\n")] = '\0';	
		i->data->tensan[strcspn(i->data->tensan, "\n")] = '\0';	
	    printf("|%-4d|%-11s|%-20s|%-5d|%-8d|%-8.2f|%-10.0f|\n",a,i->data->ID,i->data->tensan,i->data->loai,i->data->gia,i->data->gio,i->data->tien);
	    a++;
	}
	printf("|____|___________|____________________|_____|________|________|__________|\n\n");
}
void List::print2(){
    	int a=1;
	    printf("%-4s %-11s %-11s\n","STT","ID","DS DAT SAN ");
	    printf("_________________________________\n");
	for(Node *i=head;i!=NULL;i=i->next){
		if(i->data->gio==0){
		i->data->ID[strcspn(i->data->ID, "\n")] = '\0';	
	    printf("%-4d %-11s %-11s\n",a,i->data->ID,"TRONG");
	     }
	    else{
		i->data->ID[strcspn(i->data->ID, "\n")] = '\0';		
	    printf("%-4d %-11s %-11s\n",a,i->data->ID,"           ");
	   	for(int j=0;j<(i->data->sl)*2;j=j+2){ 
		printf("%-4s %-11s %-4.2f-->%-4.2f \n","    ","           ",i->data->A[j],i->data->A[j+1]);  	
	     }
         }
        printf("_________________________________\n");
         a++;
     }	   	
}

int main(){
	List list;
	int tam,tam1;
	int tam2=0;
	tam1=list.openFile();
	tam2=tam2+tam1;
	int x,y; 
	int dem;
	int k;
	int a1,A2,B,pos;
	int m1,m2,sl1;
    char ID1[10],tensan1[20],giohd1[10],diachi1[50],sdt1[11];
    int loai1;
    long gia1;
    float A1[25],gio1,tien1;
	while(true){
		printf("================MENU=================\n");
		printf("|| 1  THEM DANH SACH SAN           ||\n");
		printf("|| 2  SO SAN BONG CON HOAT DONG    ||\n");
    	printf("|| 3  XUAT DANH SACH SAN BONG      ||\n");
    	printf("|| 4  XUAT DANH SACH GIO VA TIEN   ||\n");
    	printf("|| 5  XUAT DANH SACH DAT SAN       ||\n");
    	printf("|| 6  THEM SAN BONG                ||\n");
     	printf("|| 7  XOA SAN BONG                 ||\n");
     	printf("|| 8  NHAP DANH SACH DAT SAN       ||\n");
     	printf("|| 9  SAP XEP THEO GIA SAN         ||\n");
     	printf("|| 10 SAP XEP THEO LOAI SAN        ||\n");
     	printf("|| 11 LOC SAN CON TRONG            ||\n");
    	printf("|| 0  THOAT VA LUU                 ||\n");
    	printf("=====================================\n\n\n");
    	printf("Chon phuong thuc: ");
    	scanf("%d",&x); 
		switch (x) {
		case 1:
			if(tam1>0){
        	 printf("NHAP SO LUONG SAN BONG CAN THEM: ");
        	 scanf("%d",&k);
             for(int i=1;i<=k;i++){
            	printf("\nNHAP THONG TIN SAN BONG THU: %d\n",i);
            	y=0;
            	m2=0;
            	noidung *a=nhapnoidung(y,m2,ID1,tensan1,giohd1,loai1,gia1,diachi1,sdt1,sl1,A1,gio1,tien1);
        	    list.addLast(a);
			     }
			     tam2=tam2+k;
	      	     tam=tam2;
	      	 }
	      	else{
	      		 printf("NHAP SO LUONG SAN BONG: ");
        	     scanf("%d",&k);
             for(int i=1;i<=k;i++){
            	printf("\nNHAP THONG TIN SAN BONG THU: %d\n",i);
            	y=0;
            	m2=0;
            	noidung *a=nhapnoidung(y,m2,ID1,tensan1,giohd1,loai1,gia1,diachi1,sdt1,sl1,A1,gio1,tien1);
        	    list.addLast(a);
			     }
			     tam2=tam2+k;
	      	     tam=tam2;
			  }
			break;
		case 2:	
		     list.SOSANCONHD();
			 break;
        case 3:	
             printf("\nDANH SACH SAN BONG:\n");
        	 list.print();
        	 break;
        case 4:
        	 printf("\nDANH SACH GIO VA THANH TIEN:\n");
             list.print1();
             break;
        case 5:
        	 printf("\nDANH SACH DAT SAN:\n");
             list.print2();
             break;
        case 6:
		     printf("THEM SAN VAO DAU DANH SACH NHAN PHIM 1\n");
	         printf("THEM SAN VAO CUOI DANH SACH NHAN PHIM 2\n");
	         printf("THEM SAN VAO VI TRI BAT KI NHAN PHIM 3\n");
	         scanf("%d",&a1);
		if(a1==1){
		     y=0;
		     m2=0;
		     noidung *a=nhapnoidung(y,m2,ID1,tensan1,giohd1,loai1,gia1,diachi1,sdt1,sl1,A1,gio1,tien1);
		     list.addFirst(a);
			 tam2=tam2+1;
			 tam=tam2; 	  	
	    }      
	    else if(a1==2){
	         y=0;
	         m2=0;
	         noidung *a=nhapnoidung(y,m2,ID1,tensan1,giohd1,loai1,gia1,diachi1,sdt1,sl1,A1,gio1,tien1);
	         list.addLast(a);
			 tam2=tam2+1;
			 tam=tam2;	  	    
        }
        else if(a1==3){
             y=0;
             m2=0;
             printf("NHAP VI TRI CAN CHEN\n");
             scanf("%d",&pos);
             noidung *a=nhapnoidung(y,m2,ID1,tensan1,giohd1,loai1,gia1,diachi1,sdt1,sl1,A1,gio1,tien1);
	         list.insert(a,pos);
			 tam2=tam2+1;
			 tam=tam2; 			    		
		}
        else{
		     printf("khong co lua chon %d vui long chon lai\n",a1);
		}
        break;
		case 7:
		     printf("XOA SAN DAU DANH SACH NHAN PHIM 1\n");
	         printf("XOA SAN CUOI DANH SACH NHAN PHIM 2\n");
	         printf("XOA SAN VI TRI CHON NHAN PHIM 3\n");
	         scanf("%d",&A2);
	         if(A2==1){
	         list.deleteFirst();
	         tam2=tam2-1;
			 tam=tam2;
	    	 }
	         else if(A2==2){
	         list.deleteLast();
	         tam2=tam2-1;
			 tam=tam2; 
		     }
	         else if(A2==3){
	         	 printf("nhap vi tri sam can xoa \n");
	         	scanf("%d",&pos);
	         	list.deleteAtPosition(pos);
	         	}
	         else{
	         printf("KHONG CO LUA CHON NAY VUI LONG CHON LAI");
	         }
	         break;
        case 8:
        	 printf("NHAP ID SAN CAN CAP NHAT:\n");
			 dem=list.checkID();
             if(dem==0){
             	printf("ID KHONG TON TAI !\n");
			     }
			 else
			 list.nhapdsdatsan(dem);
		 	 break;
		case 9:
			 list.Sapxep();
        	 list.print();
			 break; 
		case 10:
			 list.Sapxep1();
        	 list.print();
			 break; 
		case 11:
			 list.Loc();
			 break;      	          
        case 0:
        	 printf("DA CHAY XONG VA LUU CHUONG TRINH");
       	     list.saveFile(tam);
	    	 return 0; 
        default:
		    printf("khong co lua chon thu %d",x);
    	}
    }
}
