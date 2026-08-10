# Igraphic

version: 0.2.0

> GraphicSharedLoader

Two independently loadable contracts, not one monolithic module - a vendor
implements `IGraphic2Module` alone if it can only draw 2D, or
`IGraphic3Module` (which extends `IGraphic2Module`) if it can also do 3D.
No vendor is ever forced to fake a capability it doesn't have.

## IGraphic2Module

- window -> IWindow2
- texture -> ITexture
- font -> IFont
- polygon -> IPolygon
- sprite -> ISprite (built from an ITexture)
- text -> IText (built from an IFont)

## IGraphic3Module (extends IGraphic2Module)

- window -> IWindow3 (an IWindow3 is an IWindow2 : draws 2D too)
- camera -> ICamera
- mesh -> IMesh
- animation set -> IAnimationSet
- model -> IModel (built from an IMesh, textured via ITexture, animated via IAnimationSet)

## Window

- IWindow - lifecycle + native input, not gated by drawing capability
  - createKeyboard/createMouse/createGamepad -> IKeyboard, IMouse, IGamepad
- IWindow2 : IWindow - 2D drawing (beginDraw/drawPoly/drawSprite/drawText/endDraw)
- IWindow3 : IWindow2 - 3D drawing (beginMode3/drawModel/drawText3D/endMode3)

## ITexture / IFont / IMesh / IAnimationSet

Loaded data, independent of any ISprite/IText/IModel that references it -
deleting every sprite built from a texture does not delete the texture,
only `deleteTexture()` (or `deleteFont`/`deleteMesh`/`deleteAnimationSet`)
does. Create once, reuse across as many sprites/models as you want, delete
explicitly when you're actually done with it (level unload, not
per-object). Avoids reloading from disk every time an object pool recreates
a sprite or a model.

Audio moved out to its own repo, [iaudio](https://github.com/P-E-R-R-Y/iaudio) -
it has no coupling to a window (`InitAudioDevice()` doesn't need `InitWindow()`
in any real backend), so it doesn't belong here.
