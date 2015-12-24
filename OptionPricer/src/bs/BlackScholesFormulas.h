/*
 * BlackScholesFormulas.h
 *
 *  Created on: 2015. dec. 24.
 *      Author: Bertalan
 */

#ifndef BS_BLACKSCHOLESFORMULAS_H_
#define BS_BLACKSCHOLESFORMULAS_H_

double BlackScholesCall( 	double Spot,
							double Strike,
							double r,
							double d,
							double Vol,
							double Expiry);

double BlackScholesPut( 	double Spot,
							double Strike,
							double r,
							double d,
							double Vol,
							double Expiry);

double BlackScholesDigitalCall(	double Spot,
								double Strike,
								double r,
								double d,
								double Vol,
								double Expiry);

double BlackScholesCallVega( 	double Spot,
								double Strike,
								double r,
								double d,
								double Vol,
								double Expiry);

#endif /* BS_BLACKSCHOLESFORMULAS_H_ */
