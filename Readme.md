# Igraphic

version: 0.2.0

> GraphicSharedLoader

Two independently loadable contracts, not one monolithic module - a vendor
implements `IGraphic2Module` alone if it can only draw 2D, or
`IGraphic3Module` (which extends `IGraphic2Module`) if it can also do 3D.
No vendor is ever forced to fake a capability it doesn't have.

## IGraphic2Module

- window -> IWindow2
- polygon -> IPolygon
- sprite -> ISprite
- text -> IText

## IGraphic3Module (extends IGraphic2Module)

- window -> IWindow3 (an IWindow3 is an IWindow2 : draws 2D too)
- camera -> ICamera
- model -> IModel

## Window

- IWindow - lifecycle + native input, not gated by drawing capability
  - createKeyboard/createMouse/createGamepad -> IKeyboard, IMouse, IGamepad
- IWindow2 : IWindow - 2D drawing (beginDraw/drawPoly/drawSprite/drawText/endDraw)
- IWindow3 : IWindow2 - 3D drawing (beginMode3/drawModel/endMode3)

Audio moved out to its own repo, [iaudio](https://github.com/P-E-R-R-Y/iaudio) -
it has no coupling to a window (`InitAudioDevice()` doesn't need `InitWindow()`
in any real backend), so it doesn't belong here.
