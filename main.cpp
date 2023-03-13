#include <iostream>
#include <fstream>
#include <stack>
 
 using namespace std;
 
 int satir=0;
 int sutun=0;
 
 class maze {
	public:
		char lab[100][100];
		int i;
		int j;
};

 void print(char dizi[][100]){
 	for(int i=0;i<satir;i++){
 		for(int j=0;j<sutun;j++){
 			cout << dizi[i][j];
		 }
		 cout << endl;
	 }
	 cout << endl;
 }
 
 void textYazdirma(char dizi[][100]){
 	string girdi;
 	
 	ifstream text;
 	text.open("labirent.txt");
 	
 	getline(text,girdi);
 	sutun=girdi.length();
 	
 	text.close();
 	text.open("labirent.txt");
 	
 	while(getline(text,girdi)){
 		satir++;
	} 
	
	 	
 	text.close();
 	text.open("labirent.txt");
 	
 	
 	
 	for(int i=0;i<satir;i++){
 		getline(text,girdi);	
 		for(int j=0;j<sutun;j++){
 			dizi[i][j]=girdi[j];
		 }
	 }	
 	text.close();
 }
 
int oncelik(int y,int x,int _y,int _x){
	if(y==1){
		return 1;
	}
	else if(x==1){
		return 2;
	}
	else if(_y==1){
		return 3;
	}
	else if(_x==1){
		return 4;
	}
}

int istikamet(char dizi[][100],int i,int j){
	int x=0,y=0,_y=0,_x=0;
	
	if(dizi[i-1][j]==' '){
		y=1;
	}
	if(dizi[i][j+1]==' '){
	    x=1;
	}
	if(dizi[i+1][j]==' '){
		_y=1;
	}
	if(dizi[i][j-1]==' '){
		_x=1;
	}
 
 if(y+x+_y+_x==0){
 	return 0;
 }
 else{
 	return oncelik(y,x,_y,_x);
 }
 
}

void kopyalama(char a[][100],char dizi[][100]){
 	for(int i=0;i<satir;i++){
 		for(int j=0;j<sutun;j++){
 			a[i][j]=dizi[i][j];
		 }
	 }
 }
void kopyalama_ters(char dizi[][100],char a[][100]){
 	for(int i=0;i<satir;i++){
 		for(int j=0;j<sutun;j++){
 			dizi[i][j]=a[i][j];
		 }
	 }
 }
 
 int main(){
 	
 	char dizi[100][100];
	maze a;
	stack<maze> stack;
	
	textYazdirma(dizi); 	// txt dosyasyndan labirenti diziye kaydettim
	

	
	
	// baslangyc noktasy dizi[5][0]
	// istikamet kodunamevcut index'i ver hangi yöne gitmen gerekti?ini söylesin
	
	maze b;
	
	int yon;
	int i=5,j=0;
	
	dizi[i][j]='b';	
	a.i=i;
	a.j=j;
	kopyalama(a.lab,dizi);
	stack.push(a);
	while(dizi[i][j+1]!='y') {

		int gi,gj;

	    yon = istikamet(dizi,i,j);
	    
	    switch(yon){
		    case 0:		    	
				gi=a.i;
				gj=a.j;
				stack.pop();
				a=stack.top();
				a.lab[gi][gj]='c';
				kopyalama_ters(dizi,a.lab);
				i=a.i;
				j=a.j;						    	 	
			    break;	
		    case 1:		    
		    	cout << endl << yon << endl;;
		    	i-=1;
			    dizi[i][j]='b';
			    
			    kopyalama(a.lab,dizi);
	            a.i=i;
		        a.j=j;
	            stack.push(a);
			    break;
		    case 2:	
		    	cout << endl << yon << endl;;
		    	j+=1;
			    dizi[i][j]='b';	    
			    
			    kopyalama(a.lab,dizi);
	            a.i=i;
		        a.j=j;
	            stack.push(a);
			    break;
		    case 3:
		    	cout << endl << yon << endl;;
		    	i+=1;
			    dizi[i][j]='b';
			    
			    kopyalama(a.lab,dizi);
	            a.i=i;
		        a.j=j;
	            stack.push(a);
			    break;
		    case 4:
		    	cout << endl << yon << endl;;
		    	j-=1;
			    dizi[i][j]='b';
			    
			    kopyalama(a.lab,dizi);
	            a.i=i;
		        a.j=j;
	            stack.push(a);
			    break;
	    }
	        print(dizi);
	}
	
	cout << "Tebrikler cikisi buldunuz!!";
	
	ofstream cikti;
	cikti.open("Labirent_cevap.txt");
	
	for(int i=0;i<satir;i++){
 		for(int j=0;j<sutun;j++){
 			cikti << dizi[i][j];
		 }
		 cikti << endl;
	 }
		
 }

