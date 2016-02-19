/*
 *  Created on: Sep 3, 2015
 *      Author: Kevin Lin
 */

#ifndef DECORATION_H_
#define DECORATION_H_

class decoration {

public:

	decoration(float wt) {
		weight = wt;
	}

	float getWeight() {
		return weight;
	}

private:
	float weight;

};


#endif /* DECORATION_H_ */
