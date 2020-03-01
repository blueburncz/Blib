struct VS_out
{
	float4 Position : SV_POSITION;
	float2 TexCoord : TEXCOORD0;
};

struct PS_out
{
	float4 Surface : SV_TARGET0;
};

void main(in VS_out IN, out PS_out OUT)
{
	OUT.Surface = gm_BaseTextureObject.Sample(gm_BaseTexture, IN.TexCoord);
}