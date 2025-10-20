
## Operaciones con límites de `float`

| Operación               | Resultado esperado | Explicación breve                                                                                    |
| ----------------------- | ------------------ | ---------------------------------------------------------------------------------------------------- |
| `FLT_MAX + FLT_MAX`     | `+Inf`             | Overflow positivo.                                                                                   |
| `FLT_MAX + 1.0f`        | `FLT_MAX`          | `1` es insignificante por precisión.                                                                 |
| `FLT_MAX - FLT_MAX`     | `NaN`              | En realidad `0`. ⚠️ **Nota**: solo con `Inf - Inf` da `NaN`. Con `FLT_MAX - FLT_MAX` (finito) → `0`. |
| `FLT_MAX - 1.0f`        | `FLT_MAX`          | Diferencia insignificante.                                                                           |
| `FLT_MAX + (-FLT_MAX)`  | `0`                | Finito – finito igual da `0`. ⚠️ (NaN solo en `+Inf + -Inf`).                                        |
| `FLT_MAX * 2.0f`        | `+Inf`             | Overflow en multiplicación.                                                                          |
| `-FLT_MAX + (-FLT_MAX)` | `-Inf`             | Overflow negativo.                                                                                   |
| `+Inf + +Inf`           | `+Inf`             | Suma de infinitos del mismo signo.                                                                   |
| `-Inf + -Inf`           | `-Inf`             | Ídem.                                                                                                |
| `+Inf + -Inf`           | `NaN`              | Indefinido.                                                                                          |
| `+Inf + número finito`  | `+Inf`             | Infinito domina.                                                                                     |
| `-Inf + número finito`  | `-Inf`             | Ídem.                                                                                                |
| `NaN + x`               | `NaN`              | Cualquier operación con NaN → NaN.                                                                   |

| Operación               | Resultado esperado | Explicación breve                                                                                    |
| ----------------------- | ------------------ | ---------------------------------------------------------------------------------------------------- |
| `+Inf * 0`              | `NaN`              | Indefinido.                                                                                          |
| `+Inf * +Inf`           | `+Inf`             | Infinito al cuadrado.                                                                                |
| `+Inf * -Inf`           | `-Inf`             | Signo se conserva.                                                                                   |
| `+Inf / +Inf`           | `NaN`              | Indefinido.                                                                                          |
| `+Inf / número finito`  | `+Inf`             | Infinito dividido finito → infinito.                                                                 |
| `número finito / +Inf`  | `0`                | Resultado tiende a cero.                                                                             |
| `0 / 0`                 | `NaN`              | Indefinido.                                                                                          |
| `número / 0`            | `±Inf`             | Según el signo.                                                                                      |

| Operación               | Resultado esperado | Explicación breve                                                                                    |
| ----------------------- | ------------------ | ---------------------------------------------------------------------------------------------------- |
| `sqrtf(+Inf)`           | `+Inf`             | Raíz de infinito es infinito.                                                                        |
| `sqrtf(-Inf)`           | `NaN`              | Indefinido.                                                                                          |
| `sqrtf(NaN)`            | `NaN`              | Propaga NaN.                                                                                         |

| Operación               | Resultado esperado | Explicación breve                                                                                    |
| ----------------------- | ------------------ | ---------------------------------------------------------------------------------------------------- |
| `logf(+Inf)`            | `+Inf`             | Límite natural.                                                                                      |
| `logf(0+)`              | `-Inf`             | Tiende a menos infinito.                                                                             |
| `logf(-x)`              | `NaN`              | Logaritmo de negativo indefinido.                                                                    |

| Operación               | Resultado esperado | Explicación breve                                                                                    |
| ----------------------- | ------------------ | ---------------------------------------------------------------------------------------------------- |
| `powf(∞, positivo)`     | `+Inf`             | Crece indefinidamente.                                                                               |
| `powf(∞, 0)`            | `1`                | Definición por convenio.                                                                             |
| `powf(∞, negativo)`     | `0`                | 1/∞ = 0.                                                                                             |
| `powf(0, positivo)`     | `0`                | Base cero a exponente positivo → cero.                                                               |
| `powf(0, 0)`            | `1`                | Convenio en C.                                                                                       |
| `powf(0, negativo)`     | `+Inf`             | 1/0.                                                                                                 |
| `powf(NaN, 0)`          | `1`                | Cualquier base (excepto NaN) elevado a 0 = 1.                                                        |
| `powf(NaN, x≠0)`        | `NaN`              | Propaga NaN.                                                                                         |

---

## Comparaciones con límites de `float`

| Expresión           | Resultado esperado | Explicación                          |
| ------------------- | ------------------ | ------------------------------------ |
| `+Inf == +Inf`      | `true`             | Dos infinitos positivos son iguales. |
| `-Inf == -Inf`      | `true`             | Ídem negativos.                      |
| `+Inf == -Inf`      | `false`            | Diferente signo.                     |
| `+Inf > -Inf`       | `true`             | Positivo domina.                     |
| `+Inf > FLT_MAX`    | `true`             | Infinito mayor que cualquier finito. |
| `-Inf < -FLT_MAX`   | `true`             | Negativo domina.                     |
| `+Inf != -Inf`      | `true`             | Diferentes.                          |
| `+Inf != +Inf`      | `false`            | Iguales.                             |
| `NaN == NaN`        | `false`            | NaN no es igual ni a sí mismo.       |
| `NaN != NaN`        | `true`             | Definición IEEE-754.                 |
| `NaN < x`           | `false`            | Comparación con NaN siempre falsa.   |
| `NaN > x`           | `false`            | Ídem.                                |
| `NaN == x`          | `false`            | Ídem.                                |

| Funcion             | Resultado esperado | Explicación                          |
| ------------------- | ------------------ | ------------------------------------ |
| `isnan(NaN)`        | `true`             | Detecta NaN.                         |
| `isinf(+Inf)`       | `true`             | Detecta infinito.                    |
| `isinf(FLT_MAX)`    | `false`            | Aún finito.                          |
| `isfinite(FLT_MAX)` | `true`             | Macro para finitos.                  |
| `isfinite(+Inf)`    | `false`            | Infinito no es finito.               |
| `signbit(-Inf)`     | `true`             | Marca de signo presente.             |
| `signbit(+Inf)`     | `false`            | No tiene signo negativo.             |

