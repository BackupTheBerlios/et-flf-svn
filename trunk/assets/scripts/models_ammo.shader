// models_ammo.shader
// generated by ShaderCleaner on Thu Feb  6 12:43:32 2003
// 2 total shaders

models/ammo/rocket/rockflar
{
	cull disable
	{
		map models/ammo/rocket/rockflar.tga
		blendfunc GL_ONE GL_ONE
	}
}

models/ammo/rocket/rockfls2
{
	cull disable
	{
		map models/ammo/rocket/rockfls2.tga
		blendfunc GL_ONE GL_ONE
	}
}

models/ammo/grenade 
{ 
     { 
          map textures/effects/envmap_slate.tga 
          rgbGen lightingdiffuse 
          tcGen environment 
     } 
     { 
          map models/weapons2/grenade/grenade_yd.tga 
          blendFunc GL_ONE GL_ONE_MINUS_SRC_ALPHA 
          rgbGen lightingdiffuse 
     } 
}