💡 Q.1 What's the Box Model in CSS?

The Box Model is a fundamental concept in CSS (Cascading Style Sheets) that describes how elements are structured and displayed on a web page. It consists of four layers, or components, that wrap around an element's content. These components are:

Content: The innermost layer that contains the actual content of the element, such as text, images, or other HTML elements.

Padding: The space between the content and the element's border. It provides visual separation between the content and the border.

Border: The line that surrounds the element's padding and content. It can have a specified width, color, and style.

Margin: The space between the element's border and adjacent elements. It creates space around the element and affects its positioning in relation to other elements.

The Box Model can be visualized as follows:

```
+----------------------------------------------+
|                  Margin                      |
|    +------------------------------------+    |
|    |             Border                 |    |
|    |   +----------------------------+   |    |
|    |   |          Padding           |   |    |
|    |   |   +---------------------+  |   |    |
|    |   |   |      Content        |  |   |    |
|    |   |   +---------------------+  |   |    |
|    |   +----------------------------+   |    |
|    +------------------------------------+    |
|                  Margin                      |
+----------------------------------------------+

```

Q.2 What are the Different Types of Selectors in CSS, and what are the advantages of them?

CSS selectors are used to target specific elements on a web page and apply styles to them. Here are some commonly used CSS selectors:

Type Selectors: Select elements based on their HTML tag name. For example, p selects all <p> elements.

Class Selectors: Select elements based on their class attribute. Classes are specified using the dot (.) notation. For example, .container selects all elements with the class "container".

ID Selectors: Select a single element based on its unique ID attribute. IDs are specified using the hash (#) notation. For example, #header selects the element with the ID "header".

Attribute Selectors: Select elements based on their attribute values. For example, [type="submit"] selects all elements with the attribute type equal to "submit".

Descendant Selectors: Select elements that are descendants of another element. For example, .container p selects all <p> elements that are descendants of an element with the class "container".

Child Selectors: Select elements that are direct children of another element. For example, .container > p selects all <p> elements that are immediate children of an element with the class "container".

The advantages of different types of selectors are:

Type Selectors: They allow you to target all elements of a specific type, making it easy to apply styles consistently across the entire document.

Class Selectors: They allow you to selectively target elements based on their class, making it possible to style specific groups of elements with shared characteristics.

ID Selectors: They provide a way to uniquely identify and style individual elements on a page.

Attribute Selectors: They allow you to target elements based on their attribute values, providing flexibility in styling elements with specific attributes.

Descendant and Child Selectors: They offer control over the styling of elements that are nested within other elements, allowing for more granular targeting and styling.

By using different types of selectors, we can apply styles to specific elements or groups of elements, customize the appearance of our web page, and create consistent design patterns throughout our site.

Q.3 What is VW/VH?

VW (Viewport Width) and VH (Viewport Height) are units of measurement in CSS that allow you to size elements relative to the dimensions of the browser viewport.

VW (Viewport Width): 1 VW is equal to 1% of the width of the viewport. For example, 50vw represents 50% of the viewport width.

VH (Viewport Height): 1 VH is equal to 1% of the height of the viewport. For example, 75vh represents 75% of the viewport height.

These units are particularly useful for creating responsive designs and ensuring that elements scale proportionally with the size of the viewport. They allow you to size elements based on the available space in the viewport, making it easier to create layouts that adapt to different screen sizes.

For example, you can use VW and VH units to set the width and height of an element relative to the viewport dimensions:

```
.element {
  width: 50vw; /* 50% of the viewport width */
  height: 75vh; /* 75% of the viewport height */
}

```

Q.4 What's the difference between Inline, Inline Block, and Block?

**Inline:**
Does not start on a new line and only takes up the necessary width to fit its content.
Does not allow setting a width or height explicitly.
Margins and padding only push other inline elements horizontally, not vertically.
Examples of inline elements are `<span>, <a>, <strong>, and <em>`

**Inline Block:**

Does not start on a new line and takes up the necessary width to fit its content.
Allows setting a width, height, margins, and padding.
Margins and padding push other inline elements both horizontally and vertically.
Allows elements to have a block-like appearance while flowing inline.
Examples of inline-block elements are `<input>, <button>, and <img>.`

**Block:**

Starts on a new line and takes up the full available width of its parent container.
Allows setting a width, height, margins, and padding.
Margins and padding push other block elements both horizontally and vertically.
Can contain other block-level and inline-level elements.
Examples of block elements are `<div>, <p>, <h1> to <h6>, and <ul>.`

Q.5 How is Border-box different from Content Box?

In CSS, the box-sizing property controls how the width and height of an element are calculated, including the content, padding, and border. There are two main values for the box-sizing property:

Content Box (Default):

The width and height of an element are calculated based on the content size only.
If you set a specific width or height for an element, the padding and border will be added to the specified width/height.
This means that the total size of the element will be the specified width/height plus any padding and border added to it.

```
.element {
  box-sizing: content-box;
}

```

Border-box:

The width and height of an element are calculated including the content, padding, and border.
If you set a specific width or height for an element, the padding and border will be included in the specified width/height.
This means that the total size of the element will be the specified width/height, and the padding and border will be subtracted from it.

```
.element {
  box-sizing: border-box;
}

```

Q.6 What's z-index and how does it function?

The z-index property in CSS controls the stacking order of positioned elements that overlap in the z-axis (perpendicular to the screen). It determines which elements appear in front or behind other elements.

The z-index property takes a numeric value or the keyword auto. The higher the z-index value, the closer the element is to the top of the stacking order.

Here's how the z-index property functions:

Elements with a higher z-index value are stacked above elements with a lower z-index value within the same stacking context.

By default, elements have a z-index value of auto, which means they follow their parent's stacking order.

If multiple elements have the same z-index value, the stacking order depends on their position in the HTML structure.

💡 Q.7 What's Grid & Flex, and what's the difference between them?

Both CSS Grid and Flexbox (Flexible Box Layout) are layout systems in CSS that allow for the creation of responsive and flexible designs. Here's a summary of each:

CSS Grid:

CSS Grid is a two-dimensional layout system that divides the available space into rows and columns.
It allows you to create complex grid-based layouts where elements can be placed and aligned in both horizontal and vertical directions.
Grid layouts are defined on the parent container using the display: grid property, and child elements are positioned within the grid using grid-specific properties like grid-template-rows, grid-template-columns, and grid-area.
Grid provides precise control over the placement and sizing of elements and is well-suited for creating grid-like structures, such as magazine-like layouts or complex forms.
Flexbox (Flexible Box Layout):

Flexbox is a one-dimensional layout system that operates along a single axis, either horizontally or vertically.
It allows you to create flexible and dynamic layouts where elements can adjust their size and position to fit the available space.
Flexbox layouts are defined on the parent container using the display: flex property, and child elements become flexible items within the flex container.
Flexbox provides powerful alignment and distribution capabilities, allowing you to easily control the alignment, order, and spacing of elements.
Flexbox is particularly useful for creating responsive designs, building navigation menus, and aligning elements within a container.

Q.8 What's the difference between absolute, relative, sticky, and fixed position? Could you explain with examples?

In CSS, there are several position values that can be used to control the placement of elements on a web page. Here's an explanation of each with examples:

Static (default):

Elements with position: static are positioned according to the normal flow of the document.
They are not affected by top, bottom, left, right, or z-index properties.
Example:

```
.element {
  position: static;
}

```

Relative:

Elements with position: relative are positioned relative to their normal position in the document flow.
They can be moved using top, bottom, left, or right properties.
Other elements on the page will not be affected by the relative positioning of the element.
Example:

```
.element {
  position: relative;
  top: 10px;
  left: 20px;
}

```

Absolute:

Elements with position: absolute are positioned relative to their closest positioned ancestor (parent) or to the initial containing block if no positioned ancestor is found.
They are taken out of the normal document flow, so they don't affect the positioning of other elements.
Example:

```
.element {
  position: absolute;
  top: 0;
  left: 0;
}

```

Fixed:

Elements with position: fixed are positioned relative to the viewport, regardless of scrolling.
They stay fixed in their specified position even if the page is scrolled.
Example:

```
.element {
  position: fixed;
  top: 20px;
  right: 30px;
}

```

Sticky:

Elements with position: sticky are positioned based on the user's scroll position.
They behave like relative positioning until they reach a specified threshold, at which point they become fixed in place.
Sticky positioning is often used for navigation menus that stick to the top of the viewport as the user scrolls down.
Example:

```
.element {
  position: sticky;
  top: 50px;
}

```

Ans 9-> [Link](https://github.com/jitender1222/Placement-Assignment-INeuron/tree/main/PeriodicTable)

Ans 10-> [Link](https://github.com/jitender1222/Placement-Assignment-INeuron/tree/main/Css%20Q10%20Responsive%20Layout)
