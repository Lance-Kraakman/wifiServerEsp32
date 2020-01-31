/*
 * jsonProcessing.c
 *
 *  Created on: 10/01/2020
 *      Author: lance.kraakman
 */
#include "jsonProcessing.h"

//idea of this function is that we parse it some json string in the below format and wee add to it.
void addToJson(char * currentJson, char * jsonOject, const char * jsonValue) {

	//"{\"status_code\":-1,\"status_msg\":\"5\"}" json format for C :)
	int indexCount = 0;
	int lastBackslash = 0;

	while(*currentJson++) {
		if (*currentJson == "'\'") {
			//count to the last backslash
			lastBackslash = indexCount;
		}
		indexCount++;
	}

	//find the last occurance of the semi-colon then from there go take out the } then add another json iand add the next tings.
	if (lastBackslash == 0) {
		//we need to create the JSON.
		sprintf(currentJson, "{\"%s\":%s\}", jsonOject, jsonValue);
	} else {
		//we need to add to the json.
		//strcat appends to end of string
		//strxfrom to cut the string
		char * stringToAppend;
		sprintf(stringToAppend, "%s\":%s\}");
		//it might be lastBackslash + 1 ... or -1 ... we want to keep the backslash
		stxfrm(*currentJson,*currentJson, lastBackslash);
		strcat(*currentJson, *stringToAppend, strlen(currentJson));
	}

}
