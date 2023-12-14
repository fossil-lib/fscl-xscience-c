/*  ----------------------------------------------------------------------------
    File: demo_element.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include "trilobite/xscience/element.h" // lib source code
#include <stdio.h>

// Example usage with chemical reaction simulation
int main() {
    // Example usage of the lookup function for global elements
    celement oxygen = element_lookup("O", element_count_chart());
    celement hydrogen = element_lookup("H", element_count_chart());

    // Simulate a chemical reaction
    printf("Simulating a chemical reaction:\n");
    element_react(hydrogen, oxygen);

    // Simulate a specific reaction
    element_reaction("H", "O");

    // Get the count of elements on the chart
    size_t num_elements = element_count_chart();
    printf("\nNumber of elements on the chart: %zu\n", num_elements);

    return 0;
} // end of func
