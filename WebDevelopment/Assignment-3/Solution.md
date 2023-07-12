Q.1 What is a Media Query in CSS, and what is its purpose?

A media query in CSS is a feature that allows you to apply specific styles to a web page based on various device characteristics, such as screen size, resolution, orientation, and more. It enables you to create responsive designs that adapt and adjust based on the properties of the device or viewport on which the web page is displayed.

Q.2 How do you define a media query in CSS?

```
@media mediaType and (mediaFeature: value) {
  /* CSS rules for the specified media type and feature */
}

```

mediaType: It represents the type of media for which the styles should be applied. Common media types include all (default for all devices), screen (for computer screens), print (for printed documents), speech (for speech synthesizers), etc.
mediaFeature: It specifies the characteristic or property of the target device or viewport that you want to evaluate.
value: It represents the value of the media feature against which the condition is evaluated.

Q.3 Explain the concept of Breakpoints in Responsive Web Design and How They are used in Media Queries.

In responsive web design, breakpoints are specific points or ranges of viewport widths at which the layout or design of a web page adapts to provide an optimal viewing experience. Breakpoints are used in conjunction with media queries to define different styles or layouts for different viewport sizes.

When designing a responsive website, you typically define breakpoints based on common device sizes or your target audience's devices. For example, you might choose to have breakpoints at 480px, 768px, and 1024px, which correspond to common mobile, tablet, and desktop device widths.

Q.4 What is the purpose of using Media Queries for Print Media?

Media queries for print media are used to define specific styles that apply when a web page is printed or viewed in print preview mode. The purpose of using media queries for print media is to optimize the presentation of content specifically for printed output.

Q.5 What is the purpose of the orientation media feature?

The orientation media feature in CSS is used to target different styles based on the orientation of the device or viewport. It allows you to apply specific styles when the device is in a portrait or landscape orientation.

The purpose of the orientation media feature is to provide different layouts or adjust styles based on the screen's aspect ratio. It enables you to design responsive layouts that adapt to the device's orientation, ensuring optimal presentation and usability.
