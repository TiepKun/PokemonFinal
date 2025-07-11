/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) // Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

// Default TypedTextDatabase
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x46, 0x75, 0x6c, 0x6c, 0x48, 0x65, 0x61, 0x6c, 0xa, 0xa, 0x4c, 0x6f, 0x1ea1, 0x69, 0x20, 0x62, 0x1ecf, 0x20, 0x68, 0x6f, 0xe0, 0x6e, 0x20, 0x74, 0x6f, 0xe0, 0x6e, 0x20, 0xa, 0x74, 0x72, 0x1ea1, 0x6e, 0x67, 0x20, 0x74, 0x68, 0xe1, 0x69, 0x20, 0x62, 0x1ea5, 0x74, 0x20, 0x74, 0x68, 0x1b0, 0x1edd, 0x6e, 0x67, 0x0, // @0 "FullHeal\n\nLo?i b? ho?n to?n \ntr?ng th?i b?t th??ng"
    0x42, 0x6f, 0x6d, 0xa, 0xa, 0x47, 0xe2, 0x79, 0x20, 0x35, 0x30, 0x20, 0x73, 0xe1, 0x74, 0x20, 0x74, 0x68, 0x1b0, 0x1a1, 0x6e, 0x67, 0x20, 0xa, 0x76, 0xe0, 0x20, 0x6c, 0xe0, 0x6d, 0x20, 0x63, 0x68, 0x6f, 0xe1, 0x6e, 0x67, 0x20, 0x6b, 0x1ebb, 0x20, 0x111, 0x1ecb, 0x63, 0x68, 0x0, // @51 "Bom\n\nG?y 50 s?t th??ng \nv? l?m cho?ng k? ??ch"
    0x4d, 0x65, 0x67, 0x61, 0x52, 0x61, 0x79, 0xa, 0x75, 0x73, 0x65, 0x20, 0x44, 0x72, 0x61, 0x67, 0x6f, 0x6e, 0xa, 0x46, 0x65, 0x61, 0x72, 0x0, // @97 "MegaRay\nuse Dragon\nFear"
    0x50, 0x6f, 0x74, 0x69, 0x6f, 0x6e, 0xa, 0xa, 0x50, 0x68, 0x1ee5, 0x63, 0x20, 0x68, 0x1ed3, 0x69, 0x20, 0x35, 0x30, 0x48, 0x70, 0x0, // @121 "Potion\n\nPh?c h?i 50Hp"
    0x4d, 0x65, 0x67, 0x61, 0x52, 0x61, 0x79, 0x20, 0xa, 0x75, 0x73, 0x65, 0x20, 0x54, 0x68, 0x75, 0x6e, 0x64, 0x65, 0x72, 0x0, // @143 "MegaRay \nuse Thunder"
    0x4d, 0x65, 0x67, 0x61, 0x58, 0x20, 0x75, 0x73, 0x65, 0xa, 0x44, 0x72, 0x61, 0x67, 0x6f, 0x6e, 0x52, 0x61, 0x67, 0x65, 0x0, // @164 "MegaX use\nDragonRage"
    0x4d, 0x65, 0x67, 0x61, 0x58, 0x20, 0x75, 0x73, 0x65, 0x20, 0xa, 0x46, 0x69, 0x72, 0x65, 0x42, 0x6c, 0x61, 0x73, 0x74, 0x0, // @185 "MegaX use \nFireBlast"
    0x4d, 0x65, 0x67, 0x61, 0x58, 0x20, 0x69, 0x73, 0x20, 0xa, 0x70, 0x72, 0x6f, 0x74, 0x65, 0x63, 0x74, 0x65, 0x64, 0x0, // @206 "MegaX is \nprotected"
    0x4d, 0x65, 0x67, 0x61, 0x52, 0x61, 0x79, 0xa, 0x69, 0x73, 0x20, 0x73, 0x74, 0x75, 0x6e, 0x6e, 0x65, 0x64, 0x0, // @226 "MegaRay\nis stunned"
    0x57, 0x68, 0x61, 0x74, 0x20, 0x77, 0x69, 0x6c, 0x6c, 0xa, 0x4d, 0x65, 0x67, 0x61, 0x58, 0x20, 0x64, 0x6f, 0x0, // @245 "What will\nMegaX do"
    0x4d, 0x65, 0x67, 0x61, 0x58, 0x20, 0x75, 0x73, 0x65, 0xa, 0x50, 0x72, 0x6f, 0x74, 0x65, 0x63, 0x74, 0x0, // @264 "MegaX use\nProtect"
    0x79, 0x6f, 0x75, 0x20, 0x75, 0x73, 0x65, 0x20, 0xa, 0x46, 0x75, 0x6c, 0x6c, 0x48, 0x65, 0x61, 0x6c, 0x0, // @282 "you use \nFullHeal"
    0x4d, 0x65, 0x67, 0x61, 0x52, 0x61, 0x79, 0xa, 0x75, 0x73, 0x65, 0x20, 0x48, 0x65, 0x61, 0x6c, 0x0, // @300 "MegaRay\nuse Heal"
    0x4d, 0x65, 0x67, 0x61, 0x58, 0xa, 0x69, 0x73, 0x20, 0x73, 0x63, 0x61, 0x72, 0x65, 0x64, 0x0, // @317 "MegaX\nis scared"
    0x79, 0x6f, 0x75, 0x20, 0x75, 0x73, 0x65, 0x20, 0xa, 0x50, 0x6f, 0x74, 0x69, 0x6f, 0x6e, 0x0, // @333 "you use \nPotion"
    0x4d, 0x65, 0x67, 0x61, 0x20, 0x52, 0x61, 0x79, 0x71, 0x75, 0x61, 0x7a, 0x61, 0x0, // @349 "Mega Rayquaza"
    0x79, 0x6f, 0x75, 0x20, 0x75, 0x73, 0x65, 0x20, 0xa, 0x42, 0x6f, 0x6d, 0x0, // @363 "you use \nBom"
    0x2, 0x0, // @376 "<>"
    0x4d, 0x65, 0x67, 0x61, 0x20, 0x58, 0x0, // @378 "Mega X"
    0x42, 0x61, 0x63, 0x6b, 0x0, // @385 "Back"
    0x31, 0x35, 0x30, 0x0, // @390 "150"
    0x48, 0x50, 0x0 // @394 "HP"
};

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const uint32_t indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

// Array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

// Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            // Dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            // Compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
