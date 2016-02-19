/*
 *  Created on: Sep 3, 2015
 *      Author: Kevin Lin
 */

#ifndef BAR_H_
#define BAR_H_

class bar {

public:

	bar(int id, float ln) {
		barID = id;
		length = ln;
	}

	float getLength() {
		return length;
	}
	int getBarID() {
		return barID;
	}

private:
	int barID;
	float length; //Total length of bar

};


#endif /* BAR_H_ */
