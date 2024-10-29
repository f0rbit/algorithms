function evaluate(s: string, knowledge: string[][]): string {
    const k_map = new Map();
    knowledge.forEach((s) => {
        k_map.set(s[0], s[1]);
    });

    while (s.includes("(")) {
        const start = s.indexOf("(");
        const end = s.indexOf(")");
        const inside = s.substring(start + 1, end);
        let replace = "?";
        if (k_map.has(inside)) {
            replace = k_map.get(inside);
        }
        s = s.substring(0, start) + replace + s.substring(end + 1);
    }

    return s;
};
