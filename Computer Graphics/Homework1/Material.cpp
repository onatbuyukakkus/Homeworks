#include "Material.h"
#include <math.h>
#include "Scene.h"
#include <cfloat>
using namespace std;

float dotProduct2(Vector3 vect1, Vector3 vect2) {
	return vect1._data[0]*vect2._data[0]+vect1._data[1]*vect2._data[1]+vect1._data[2]*vect2._data[2];
}

float calculateLenght(Vector3 point1, Vector3 point2) {
	return sqrt(pow((point1._data[0]-point2._data[0]),2)+pow((point1._data[1]-point2._data[1]),2)+pow((point1._data[2]-point2._data[2]),2));
}

Vector3 normalize(Vector3 vect) {
	float size = sqrt(pow(vect._data[0],2)+pow(vect._data[1],2)+pow(vect._data[2],2));
	Vector3 res;
	res._data[0]=vect._data[0]/size;
	res._data[1]=vect._data[1]/size;
	res._data[2]=vect._data[2]/size;
	return res;
}

Color Material::calculateAmbient(){

	float redResult;
	float greenResult;
	float blueResult;
	redResult = CurrentScene->getAmbient().R()*_ambient.R();
	greenResult = CurrentScene->getAmbient().G()*_ambient.G();
	blueResult = CurrentScene->getAmbient().B()*_ambient.B();

	Color result(redResult, greenResult, blueResult);
	return result;
}


Color Material::calculateColor(Vector3 rayHitNormal, Vector3 rayHitPosition, Vector3 position, int reflectionCounter) {
	
	float resultRed = calculateAmbient().R();
	float resultGreen = calculateAmbient().G();
	float resultBlue = calculateAmbient().B();
	int refFlag=0;

	for(int n=0; n<CurrentScene->lightsSize(); n++) {
		float t_max = FLT_MAX;
		float R=0;
		float G=0;
		float B=0;
		PointLight currentLight = CurrentScene->getPointLight(n);

		Vector3 lightHit;
		lightHit._data[0] = currentLight._X - rayHitPosition._data[0];
		lightHit._data[1] = currentLight._Y - rayHitPosition._data[1];
		lightHit._data[2] = currentLight._Z - rayHitPosition._data[2];
		float lightHitSize = sqrt(pow(lightHit._data[0],2)+pow(lightHit._data[1],2)+pow(lightHit._data[2],2));
		lightHit = normalize(lightHit);

		Vector3 cameraHit;
		cameraHit._data[0] = position._data[0] - rayHitPosition._data[0];
		cameraHit._data[1] = position._data[1] - rayHitPosition._data[1];
		cameraHit._data[2] = position._data[2] - rayHitPosition._data[2];
		cameraHit = normalize(cameraHit);

		if(refFlag==0, _reflectance.R()!=0 && _reflectance.G()!=0 && _reflectance.B()!=0 && (reflectionCounter < CurrentScene->getRayReflect())) {
			refFlag++;
			Vector3 wr;
			wr._data[0]= -1*cameraHit._data[0] + 2*rayHitNormal._data[0]*dotProduct2(rayHitNormal, cameraHit);
			wr._data[1]= -1*cameraHit._data[1] + 2*rayHitNormal._data[1]*dotProduct2(rayHitNormal, cameraHit);
			wr._data[2]= -1*cameraHit._data[2] + 2*rayHitNormal._data[2]*dotProduct2(rayHitNormal, cameraHit);
			wr = normalize(wr);

			float wr0 = wr._data[0]*0.002;
			float wr1 = wr._data[1]*0.002;
			float wr2 = wr._data[2]*0.002;

			Vector3 rayPos;
			rayPos._data[0] = rayHitPosition._data[0] + wr0;
			rayPos._data[1] = rayHitPosition._data[1] + wr1;
			rayPos._data[2] = rayHitPosition._data[2] + wr2;

			Ray currentRay(rayPos, wr);
			RayHitInfo reflectInfo;
			RayHitInfo saveInfo;

			for(int k=0; k<CurrentScene->spheresSize(); k++) {
				if((CurrentScene->getSphere(k).Intersect(currentRay, reflectInfo))==true) {
					if(reflectInfo.Parameter < t_max) {
						t_max=reflectInfo.Parameter;
						saveInfo = reflectInfo;
					}
				}
			}

			for(int l=0; l<CurrentScene->meshesSize(); l++) {
				Mesh currentMesh = CurrentScene->getMesh(l);
				for(int m=0; m<currentMesh._triangles.size(); m++) {
					if((currentMesh._triangles[m].Intersect(currentRay, reflectInfo))==true) {
						if(reflectInfo.Parameter < t_max) {
							t_max=reflectInfo.Parameter;
							saveInfo=reflectInfo;
						}
					}
				}
			}

			if(t_max != FLT_MAX){
				Material currentMaterial=CurrentScene->getMaterial(saveInfo.Material-1);
				Color result;
				result = currentMaterial.calculateColor(saveInfo.Normal, saveInfo.Position, rayHitPosition, ++reflectionCounter);
				Color temp(result.R()*_reflectance.R(), result.G()*_reflectance.G(), result.B()*_reflectance.B());
				resultRed += temp.R();
				resultGreen += temp.G();
				resultBlue += temp.B();
			}
		}

		//shadow
		Vector3 origin;
		origin._data[0] = (0.001 * lightHit._data[0]) + rayHitPosition._data[0];
		origin._data[1] = (0.001 * lightHit._data[1]) + rayHitPosition._data[1];
		origin._data[2] = (0.001 * lightHit._data[2]) + rayHitPosition._data[2];
		Ray shadowRay(origin, lightHit);

		Vector3 curLight;
		curLight._data[0]=currentLight._X;
		curLight._data[1]=currentLight._Y;
		curLight._data[2]=currentLight._Z;
		float len_min = calculateLenght(rayHitPosition, curLight);
		RayHitInfo rayHitShadowSphere;
		float currentLenSphere;
		int flag=0;
		for(int r=0; r<CurrentScene->spheresSize(); r++) {
			if((CurrentScene->getSphere(r).Intersect(shadowRay, rayHitShadowSphere))==true) {
				currentLenSphere = calculateLenght(rayHitShadowSphere.Position, rayHitPosition);
				if(currentLenSphere < len_min) {flag=1;break;}
			}
		}
		float currentLenMesh;
		RayHitInfo rayHitShadowMesh;
		for(int s=0; s<CurrentScene->meshesSize(); s++) {
			Mesh curMesh = CurrentScene->getMesh(s);
			int triSize = curMesh._triangles.size();
			for(int o=0; o<triSize; o++) {
				if((curMesh._triangles[o].Intersect(shadowRay, rayHitShadowMesh))==true) {
					currentLenMesh = calculateLenght(rayHitShadowMesh.Position, rayHitPosition);
					if(currentLenMesh < len_min) {flag=1;break;}
				}
			}	
			if(flag==1) break;
		}
		if(flag == 0) {
			Vector3 I;
			I._data[0] = (currentLight._intensity._data[0]/(4*M_PI*pow(lightHitSize,2)));
			I._data[1] = (currentLight._intensity._data[1]/(4*M_PI*pow(lightHitSize,2)));
			I._data[2] = (currentLight._intensity._data[2]/(4*M_PI*pow(lightHitSize,2)));

			float cosTeta = dotProduct2(rayHitNormal, lightHit);
			if(cosTeta < 0) cosTeta = 0;
			
			float a = cosTeta*I._data[0];
			float b = cosTeta*I._data[1];
			float c = cosTeta*I._data[2];

			R += a*_diffuse.R();
			G += b*_diffuse.G();
			B += c*_diffuse.B();


			//specular
			Vector3 h;
			h._data[0] = cameraHit._data[0] + lightHit._data[0];
			h._data[1] = cameraHit._data[1] + lightHit._data[1];
			h._data[2] = cameraHit._data[2] + lightHit._data[2];
			float hSize = sqrt(pow(h._data[0],2)+pow(h._data[1],2)+pow(h._data[2],2));
			h._data[0] = h._data[0]/hSize;
			h._data[1] = h._data[1]/hSize;
			h._data[2] = h._data[2]/hSize;

			float cosAlfa = dotProduct2(rayHitNormal, h);
			if (cosAlfa < 0) cosAlfa=0; 

			R += _specular.R()*(pow(cosAlfa,_specularSpecExp))*I._data[0];
			G += _specular.G()*(pow(cosAlfa,_specularSpecExp))*I._data[1];
			B += _specular.B()*(pow(cosAlfa,_specularSpecExp))*I._data[2];

			Color result = *(new Color(R,G,B));
			resultRed += result.R();
			resultGreen += result.G();
			resultBlue += result.B();
		}
	}
	Color final(resultRed, resultGreen, resultBlue);
	return final;
}


/*t_max = rayHitSphere.Parameter;
						Material currentMat = CurrentScene->getMaterial(rayHitSphere.Material-1);

						Color ambient = currentMat.calculateAmbient();
						float resultRed = ambient.R();
						float resultGreen = ambient.G();
						float resultBlue = ambient.B();

						for(int n=0; n<CurrentScene->lightsSize(); n++) {
							PointLight currentLight = CurrentScene->getPointLight(n);

							//RAY CALCULATION/////////////////////////////////////////////////////////////
							Vector3 lightHit;
							lightHit._data[0] = currentLight._X - rayHitSphere.Position._data[0];
							lightHit._data[1] = currentLight._Y - rayHitSphere.Position._data[1];
							lightHit._data[2] = currentLight._Z - rayHitSphere.Position._data[2];
							float lightHitSize = sqrt(pow(lightHit._data[0],2)+pow(lightHit._data[1],2)+pow(lightHit._data[2],2));
							lightHit._data[0] = lightHit._data[0] / lightHitSize;
							lightHit._data[1] = lightHit._data[1] / lightHitSize;
							lightHit._data[2] = lightHit._data[2] / lightHitSize;
							
							//SHADOW CALCULATION/////////////////////////////////////////////////////////////
							Vector3 curLight;
							curLight._data[0]=currentLight._X;
							curLight._data[1]=currentLight._Y;
							curLight._data[2]=currentLight._Z;
							float len_min = calculateLenght(rayHitSphere.Position, curLight);
							RayHitInfo rayHitShadowSphere;
							float currentLenSphere;
							int flag = 0;
							//float light_t=(currentLight._Y-rayHitSphere.Position._data[1]-origin._data[1])/lightHit._data[1];
							for(int r=0; r<spheresSize; r++) {
								if((CurrentScene->getSphere(r).Intersect(shadowRay, rayHitShadowSphere))==true) {
									currentLenSphere = calculateLenght(rayHitShadowSphere.Position, rayHitSphere.Position);
									if(currentLenSphere < len_min) {flag=1;break;}
								}
							}
							//if(flag==1) continue;
							float currentLenMesh;
							RayHitInfo rayHitShadowMesh;
							for(int s=0; s<meshesSize; s++) {
								Mesh curMesh = CurrentScene->getMesh(s);
								int triSize = curMesh._triangles.size();
								for(int o=0; o<triSize; o++) {
									if((curMesh._triangles[o].Intersect(shadowRay, rayHitShadowMesh))==true) {
										currentLenMesh = calculateLenght(rayHitShadowMesh.Position, rayHitSphere.Position);
										if(currentLenMesh < len_min) {flag=1;break;}
									}
								}	
								if(flag==1) break;
							}
							//////////////////////////////////////////////////////////////////////////////
							if(flag==0) {
							Color result = currentMat.calculateColor(rayHitSphere.Normal,
															rayHitSphere.Position, currentLight._intensity, currentLight._X,
																				currentLight._Y, currentLight._Z, _position);
							resultRed += result.R();
							resultGreen += result.G();
							resultBlue += result.B();}
						}
						img.Pixel(i,j) = *(new Color(resultRed,resultGreen,resultBlue));	
					}
				}*/



/*t_max = rayHitTriangle.Parameter;
							Material currentMat = CurrentScene->getMaterial(rayHitTriangle.Material-1);

							Color ambient = currentMat.calculateAmbient();
							float resultRed = ambient.R();
							float resultGreen = ambient.G();
							float resultBlue = ambient.B();

							for(int p=0; p<CurrentScene->lightsSize(); p++) {
								PointLight currentLight = CurrentScene->getPointLight(p);

								//RAY CALCULATION/////////////////////////////////////////////////////////////
								Vector3 lightHit;
								lightHit._data[0] = currentLight._X - rayHitTriangle.Position._data[0];
								lightHit._data[1] = currentLight._Y - rayHitTriangle.Position._data[1];
								lightHit._data[2] = currentLight._Z - rayHitTriangle.Position._data[2];
								float lightHitSize = sqrt(pow(lightHit._data[0],2)+pow(lightHit._data[1],2)+pow(lightHit._data[2],2));
								lightHit._data[0] = lightHit._data[0] / lightHitSize;
								lightHit._data[1] = lightHit._data[1] / lightHitSize;
								lightHit._data[2] = lightHit._data[2] / lightHitSize;
								Vector3 origin;
								origin._data[0] = (0.001 * lightHit._data[0]) + rayHitTriangle.Position._data[0];
								origin._data[1] = (0.001 * lightHit._data[1]) + rayHitTriangle.Position._data[1];
								origin._data[2] = (0.001 * lightHit._data[2]) + rayHitTriangle.Position._data[2];

								Ray shadowRay(origin, lightHit);
								//SHADOW CALCULATION/////////////////////////////////////////////////////////////
								Vector3 curLight;
								curLight._data[0]=currentLight._X;
								curLight._data[1]=currentLight._Y;
								curLight._data[2]=currentLight._Z;
								float len_min = calculateLenght(rayHitTriangle.Position, curLight);
								RayHitInfo rayHitShadowSphere;
								float currentLenSphere;
								int flag = 0;
								float light_t=(currentLight._Y-rayHitSphere.Position._data[1]-origin._data[1])/lightHit._data[1];
								for(int r=0; r<spheresSize; r++) {
									if((CurrentScene->getSphere(r).Intersect(shadowRay, rayHitShadowSphere))==true) {
										currentLenSphere = calculateLenght(rayHitShadowSphere.Position, rayHitTriangle.Position);
										if(currentLenSphere < len_min) {flag=1;break;}
									}
								}
								//if(flag==1) continue;
								float currentLenMesh;
								RayHitInfo rayHitShadowMesh;
								for(int s=0; s<meshesSize; s++) {
									Mesh curMesh = CurrentScene->getMesh(s);
									int triSize = curMesh._triangles.size();
									for(int o=0; o<triSize; o++) {
										if((curMesh._triangles[o].Intersect(shadowRay, rayHitShadowMesh))==true) {
											currentLenMesh = calculateLenght(rayHitShadowMesh.Position, rayHitTriangle.Position);
											if(currentLenMesh < len_min) {flag=1;break;}
										}
									}	
									if(flag==1) break;
								}
								//if(flag==1) continue;
								//////////////////////////////////////////////////////////////////////////////
								if(flag==0) {
								Color result = currentMat.calculateColor(rayHitTriangle.Normal,
																rayHitTriangle.Position, currentLight._intensity, currentLight._X,
																					currentLight._Y, currentLight._Z, _position);
								resultRed += result.R();
								resultGreen += result.G();
								resultBlue += result.B();}
							}
							img.Pixel(i,j) = *(new Color(resultRed,resultGreen,resultBlue));
						}
					}*/