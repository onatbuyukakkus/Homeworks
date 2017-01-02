#include "Material.h"
#include "Scene.h"
#include <algorithm>
#include <cmath>
#include "Ray.h"
using namespace std;

int resize(int x, int dimension) {
    if(x > dimension-1) {
        return dimension-1;
    }
    if(x < 0) {
        return 0;
    }
    else {
        return x;
    }
}

Material Material::Diffuse(const Color &color)
{
    Material m;
    m._diffuse = color;
    return m;
}

Color Material::Calculate(const Vector3 &normal, const Vector3 &pointOfIntersection, const Vector3 &viewDirection,
                          const Scene *scene, int hitCount, int sphereId, int triangleId, float beta, float gamma) const
{
    if(sphereId > -1 && triangleId == -1) {
        ////////////////////////////
        /*std::cout << "Top-left pixel's (R, G, B) values: ";
        std::cout << "(" << (int) scene->GetTexture(textureId)[0][0][0] << ", ";
        std::cout << (int) scene->GetTexture(textureId)[0][0][1] << ", ";
        std::cout << (int) scene->GetTexture(textureId)[0][0][2] << ")" << std::endl;
        std::cout << "Height: " << scene->GetTextureHeight(textureId) << std::endl;
        std::cout << "Width: " << scene->GetTextureWidth(textureId) << std::endl;*/
        int textureId = scene->Spheres()[sphereId-1].GetTextureId();
        //int radius = scene->Spheres()[sphereId-1].GetRadius();
        //VertexId vertexId = scene->Spheres()[sphereId-1].GetCenterId();
        //Vector3 center = scene->GetVertex(vertexId).Position();

        int width = scene->GetTextureWidth(textureId);
        int height = scene->GetTextureHeight(textureId);
        /////////////////////////////


        float _channels[3] =
                {
                        scene->AmbientLight().R() * _ambient.R(),
                        scene->AmbientLight().G() * _ambient.G(),
                        scene->AmbientLight().B() * _ambient.B()
                };

        if (hitCount && _reflectance.R() > 0 && _reflectance.G() > 0 && _reflectance.B() > 0) {
            Color reflectionColor;
            CalculateReflectance(reflectionColor, normal, viewDirection, pointOfIntersection, scene, hitCount);
            _channels[0] += reflectionColor.R() * _reflectance.R();
            _channels[1] += reflectionColor.G() * _reflectance.G();
            _channels[2] += reflectionColor.B() * _reflectance.B();
        }

        Ray shadowRay(pointOfIntersection + normal * 0.0001f, Vector3::Zero);
        for (const auto &light : scene->Lights()) {

            RayHitInfo shadowInfo;
            float distanceSqr;

            Vector3 lightRayDir = light.Position() - pointOfIntersection;
            distanceSqr = lightRayDir.SquaredMagnitude();
            lightRayDir.Normalize();

            shadowRay.Direction(lightRayDir);
            if (scene->Raycast<false>(shadowRay, shadowInfo) && shadowInfo.Parameter * shadowInfo.Parameter < distanceSqr) {
                continue;
            }

            Color intensity = light.Intensity(pointOfIntersection);
            Vector3 lightViewHalf = (viewDirection + lightRayDir).Normalized();

            float diffuseCoefficient = std::max(0.0f, Vector3::Dot(normal, lightRayDir));
            float specularCoefficient = std::pow(std::max(0.0f, Vector3::Dot(normal, lightViewHalf)), _phong);

            ///////////////////////////////////////////////////
            _channels[0] += intensity.R() * (_specular.R() * specularCoefficient);

            _channels[1] += intensity.G() * (_specular.G() * specularCoefficient);

            _channels[2] += intensity.B() * (_specular.B() * specularCoefficient);

            if(textureId == 0) {
                _channels[0] += intensity.R() * (_diffuse.R() * diffuseCoefficient);

                _channels[1] += intensity.G() * (_diffuse.G() * diffuseCoefficient);

                _channels[2] += intensity.B() * (_diffuse.B() * diffuseCoefficient);
            }
            else {
                ///////TEXTURE MAPPING////////
                VertexId vertexId = scene->Spheres()[sphereId-1].GetCenterId();
                Vector3 center = scene->GetVertex(vertexId).Position();

                Vector3 newNorm = normal;
                Vector3 upCenter = scene->Spheres()[sphereId-1].GetUp() - center;                
                Vector3 rightCenter = scene->Spheres()[sphereId-1].GetRight() - center;
                
                Vector3 resultVector = ((newNorm/newNorm.Magnitude()) - ( (upCenter/upCenter.Magnitude()) * (Vector3::Dot((newNorm/newNorm.Magnitude()), (upCenter/upCenter.Magnitude())))));

                float angle = acos(Vector3::Dot((upCenter/upCenter.Magnitude()), (newNorm/newNorm.Magnitude())));
                float angle2 = acos(Vector3::Dot((rightCenter/rightCenter.Magnitude()), (resultVector/resultVector.Magnitude())));

                float u = (M_PI - angle2) / (2 * M_PI);
                float v = 1 - ((M_PI - angle) / M_PI);

                int i = round(u*width); i = resize(i, width);
                int j = round(v*height); j = resize(j, height);       

                Color textureColor(scene->GetTexture(textureId)[j][i][0], scene->GetTexture(textureId)[j][i][1], scene->GetTexture(textureId)[j][i][2]);

                _channels[0] += textureColor.R() * (_diffuse.R() * diffuseCoefficient);

                _channels[1] += textureColor.G() * (_diffuse.G() * diffuseCoefficient);

                _channels[2] += textureColor.B() * (_diffuse.B() * diffuseCoefficient);
            }    
        }
        return Color(_channels[0], _channels[1], _channels[2]);
    }
    else if(triangleId > -1 && sphereId == -1) {        
        int textureId = scene->Triangles()[triangleId-1].GetTextureId();

        int width = scene->GetTextureWidth(textureId);
        int height = scene->GetTextureHeight(textureId);

        float _channels[3] =
                {
                        scene->AmbientLight().R() * _ambient.R(),
                        scene->AmbientLight().G() * _ambient.G(),
                        scene->AmbientLight().B() * _ambient.B()
                };

        if (hitCount && _reflectance.R() > 0 && _reflectance.G() > 0 && _reflectance.B() > 0) {
            Color reflectionColor;
            CalculateReflectance(reflectionColor, normal, viewDirection, pointOfIntersection, scene, hitCount);
            _channels[0] += reflectionColor.R() * _reflectance.R();
            _channels[1] += reflectionColor.G() * _reflectance.G();
            _channels[2] += reflectionColor.B() * _reflectance.B();
        }

        Ray shadowRay(pointOfIntersection + normal * 0.0001f, Vector3::Zero);
        for (const auto &light : scene->Lights()) {

            RayHitInfo shadowInfo;
            float distanceSqr;

            Vector3 lightRayDir = light.Position() - pointOfIntersection;
            distanceSqr = lightRayDir.SquaredMagnitude();
            lightRayDir.Normalize();

            shadowRay.Direction(lightRayDir);
            if (scene->Raycast<false>(shadowRay, shadowInfo) && shadowInfo.Parameter * shadowInfo.Parameter < distanceSqr) {
                continue;
            }

            Color intensity = light.Intensity(pointOfIntersection);
            Vector3 lightViewHalf = (viewDirection + lightRayDir).Normalized();

            float diffuseCoefficient = std::max(0.0f, Vector3::Dot(normal, lightRayDir));
            float specularCoefficient = std::pow(std::max(0.0f, Vector3::Dot(normal, lightViewHalf)), _phong);

            _channels[0] += intensity.R() * (_specular.R() * specularCoefficient);

            _channels[1] += intensity.G() * (_specular.G() * specularCoefficient);

            _channels[2] += intensity.B() * (_specular.B() * specularCoefficient);

            if(textureId == 0) {
                _channels[0] += intensity.R() * (_diffuse.R() * diffuseCoefficient);

                _channels[1] += intensity.G() * (_diffuse.G() * diffuseCoefficient);

                _channels[2] += intensity.B() * (_diffuse.B() * diffuseCoefficient);
            }
            else {
                ///////TEXTURE MAPPING////////
                float u_a = scene->Triangles()[triangleId-1].GetUvs()[0][0];
                float v_a = scene->Triangles()[triangleId-1].GetUvs()[0][1];

                float u_b = scene->Triangles()[triangleId-1].GetUvs()[1][0];
                float v_b = scene->Triangles()[triangleId-1].GetUvs()[1][1];

                float u_c = scene->Triangles()[triangleId-1].GetUvs()[2][0];
                float v_c = scene->Triangles()[triangleId-1].GetUvs()[2][1];

                float u = u_a + beta*(u_b - u_a) + gamma*(u_c - u_a); if(u<0) u=0;
                float v = v_a + beta*(v_b - v_a) + gamma*(v_c - v_a); if(v<0) v=0;
                float v2 = 1-v;

                int i = round((u)*width); if(i<=0) i+=1;
                int j = round(v2*height); if(j<=0) j+=1;


                Color textureColor(scene->GetTexture(textureId)[height-j][i][0], scene->GetTexture(textureId)[height-j][i][1], scene->GetTexture(textureId)[height-j][i][2]);

                _channels[0] += textureColor.R() * (_diffuse.R() * diffuseCoefficient);

                _channels[1] += textureColor.G() * (_diffuse.G() * diffuseCoefficient);

                _channels[2] += textureColor.B() * (_diffuse.B() * diffuseCoefficient);

            }    
        }
        return Color(_channels[0], _channels[1], _channels[2]);
        /////////////////////////////////////////////////////////////
    }
    
}

///////////////////////////////////////////////////
void Material::CalculateReflectance(Color &reflectedColor, const Vector3 &normal, const Vector3 &rayDirection,
                                    const Vector3 &pointOfIntersection, const Scene *scene, int hitCount) const
{
    float cosAlpha = Vector3::Dot(rayDirection, normal);
    Vector3 reflectedRayDirection = (2 * cosAlpha * normal - rayDirection).Normalized();
    Ray reflectedRay(pointOfIntersection + normal * 0.0001, reflectedRayDirection);

    RayHitInfo hitInfo;
    if (scene->FastRaycast(reflectedRay, hitInfo)) {
        reflectedColor =
                scene->GetMaterial(hitInfo.Material).Calculate(hitInfo.Normal, hitInfo.Position,
                                                               -reflectedRay.Direction(), scene, hitCount - 1, hitInfo.SphereId, hitInfo.TriangleId, hitInfo.Beta, hitInfo.Gamma);
    }
}
///////////////////////////////////////////////////


std::istream &operator>>(std::istream &stream, Material &mat)
{
    stream >> mat._ambient;
    stream >> mat._diffuse;
    stream >> mat._specular;
    stream >> mat._phong;
    stream >> mat._reflectance;

    return stream;
}

