// rubble.shader
// generated by ShaderCleaner on Thu Feb  6 12:43:32 2003
// 5 total shaders

textures/rubble/burn_flr_m01
{
	surfaceparm woodsteps
	implicitMap -
}

textures/rubble/burn_flr_m01a
{
	qer_editorimage textures/rubble/burn_flr_m01a.tga
	surfaceparm pointlight
	surfaceparm woodsteps
	{
		map textures/props/ember1a.tga
		rgbGen wave sin 1 0.5 0 0.5
		tcmod rotate 3
	}
	{
		map textures/rubble/burn_flr_m01a.tga
		blendfunc blend
		rgbGen vertex
	}
}

textures/rubble/burn_flr_m01b
{
	qer_editorimage textures/rubble/burn_flr_m01a.tga
	surfaceparm pointlight
	surfaceparm woodsteps
	{
		map textures/props/ember1a.tga
		rgbGen wave sin 1 0.45 0 0.5
		tcmod rotate -3
	}
	{
		map textures/rubble/burn_flr_m01a.tga
		blendfunc blend
		rgbGen vertex
	}
}

textures/rubble/burn_flr_m01c
{
	qer_editorimage textures/rubble/burn_flr_m01a.tga
	surfaceparm pointlight
	surfaceparm woodsteps
	{
		map textures/props/ember1a.tga
		rgbGen wave sin 1 0.55 0 0.5
		tcmod rotate 3.2
	}
	{
		map textures/rubble/burn_flr_m01a.tga
		blendfunc blend
		rgbGen vertex
	}
}

textures/rubble/rebar_m01
{
	cull none
	surfaceparm metalsteps
	implicitMask -
}
