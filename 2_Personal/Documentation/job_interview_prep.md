←, ↑, →, ↓  Unicode arrows
# Job Interview prep (C# and React typescript)

### Wat is het verschil tussen een struct en een class in c#?
> - Een struct is een value type → stack.
> - Een class is een reference type → heap.

### Wat zijn interfaces in C# en waarom gebruik je ze?
> een interface definieert een contract of blueprint van members, maar zonder implementatie (wat wel moet op bij de classes die de interface implementeert)

### Leg de termen async en await uit in  C#?
> Deze dienen voor asynchrone code te schrijven. await laat toe om calls te maken naar functies die gedefinieerd zijn met het async sleutelwoord. Asynchrone functies laten je toe om taken uit te voeren zonder de hoofdthread the blokkeren.

### Wat is een lambda expressie in C#?
> Een beknopte manier om anonieme functies te definieren.

```csharp
// example lambda expression
Func<int, int> square = x => x*x;
```

### Wat is het verschil tussen een abstracte klasse en een interface in C#?
> Een abstracte class kan zowel members met als zonder implementatie hebben, terwijl een interface enkel zonder implementatie bevat. abstract classes dienen kunnen niet geinstantieerd worden en dienen voornamelijk als een gedeeld startpunt voor de afgeleide classes.

### Hoe werkt garbage collection in C#?
> De garbage collector beheert het geheugen door objecten die niet meer gebruikt worden, automatisch vrij te geven.

### Wat is een delegate in C#?
