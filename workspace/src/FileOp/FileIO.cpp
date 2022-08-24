/*
*	FileIOクラス
*	作成者：崎山
*/

#include "../../include/FileOp/FileIO.hpp"

/*
*	ファイル読み込み
*	destinationにファイルデータを格納する
*/
char FileIO::read(vector<char>& destination,char* file_path){
	FILE *fp;

	if (( fp = fopen ( file_path,"r" )) == NULL ){
		printf("file open err\n");
		return -1;
	}

	if ( fread( &destination[0],destination.size(),1,fp ) == 0 ){
		printf("file read err\n");
		return -1;
	}

	fclose(fp);

	return 0;
}



int FileIO::getSize(char* file_path){

	FILE *fp;
	int fsize = 0;

	if (( fp = fopen ( file_path,"r" )) == NULL ){
		printf("file open err\n");
		return -1;
	}

	while (true) {
        if (fgetc(fp) == EOF) {
            if (feof(fp)) {
                break;
            }
            else if (ferror(fp)) {
                fclose(fp);
				break;
            }
		}
		fsize++;
    }

	fclose(fp);

	return fsize;

}